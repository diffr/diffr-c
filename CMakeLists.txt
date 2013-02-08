# CMake build script for diff-c project.
#
# This file is part of diffr-c.
# 
# diffr-c is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# diffr-c is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with diffr-c.  If not, see <http://www.gnu.org/licenses/>.
# 

cmake_minimum_required (VERSION 2.6.2)

########
# Main #
########

project (diffr-c)

set(TESTING "NONE" CACHE STRING "NONE")
set(COVERAGE "NONE" CACHE STRING "NONE")

set(DIFFR_DIFFNAME diffr)
set(DIFFR_PATCHNAME patchr)
set(DIFFR_UTIL diffr-util)
set(DIFFR_SUFFIXTREE diffr-suffixTree)
set(DIFFR_DIFF diffr-diff)
set(DIFFR_PATCH diffr-patch)
set(DIFFR_SOURCE_DIR src)
set(DIFFR_INCLUDE_DIR include)
set(DIFFR_TEST_DIR test/src)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(PkgConfig)
find_package(Glib)
include_directories(
    ${DIFFR_INCLUDE_DIR}
    ${GLIB_INCLUDE_DIRS}
)

# list all source files here
# TODO: replace this with a macro

add_library (${DIFFR_UTIL}
    ${DIFFR_SOURCE_DIR}/util/ArgumentsProcessor.c
    ${DIFFR_SOURCE_DIR}/util/instruction/Instruction.c
    )

add_library (${DIFFR_SUFFIXTREE}
    ${DIFFR_SOURCE_DIR}/suffixtree/SuffixTrees.c
    )

add_library (${DIFFR_DIFF}
    ${DIFFR_SOURCE_DIR}/diff/Diffr.c
    )

add_library (${DIFFR_PATCH}
    ${DIFFR_SOURCE_DIR}/patch/Patchr.c
    )

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################

message("-- Testing mode: ${TESTING}")

IF(("FAST" STREQUAL TESTING) OR ("ALL" STREQUAL TESTING))

    message("-- Testing is enabled.")

    set(Boost_USE_MULTITHREADED ON)
    find_package(Boost COMPONENTS 
        unit_test_framework
        REQUIRED)
    enable_testing(true)

    include_directories(
        ${Boost_INCLUDE_DIRS}
    )

    #################
    # Code coverage #
    #################

    message("-- Coverage mode: ${COVERAGE}")
    if(("LCOV" STREQUAL COVERAGE) OR ("COBERTURA" STREQUAL COVERAGE))

      set(CMAKE_BUILD_TYPE "Debug")

      if(NOT (CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX))
        message("-- Compiler not GNU, cannot create coverage report.")
      else()
        include(CodeCoverage)
        message("-- Code coverage is enabled.")

        if("LCOV" STREQUAL COVERAGE)
          SETUP_TARGET_FOR_COVERAGE(coverage ctest coverage)
        else()
          SETUP_TARGET_FOR_COVERAGE_COBERTURA(coverage ctest coverage)
        endif()

      endif()

    endif()
	
    # list test definitions here
    # TODO: replace this with a macro

    add_executable(UtilTests
        ${DIFFR_TEST_DIR}/util/ArgumentsProcessorTest.cpp
        ${DIFFR_TEST_DIR}/util/instruction/InstructionTest.cpp
    )
    target_link_libraries(UtilTests
        ${DIFFR_UTIL}
        ${GLIB_LIBRARIES}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )
    add_test(UtilTests UtilTests)

    add_executable(SuffixTreeTests
        ${DIFFR_TEST_DIR}/suffixtree/SuffixTreesTest.cpp
    )
    target_link_libraries(SuffixTreeTests
        ${DIFFR_SUFFIXTREE}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )
    add_test(SuffixTreeTests SuffixTreeTests)

    add_executable(DiffrTests
        ${DIFFR_TEST_DIR}/diff/DiffrTest.cpp
    )
    target_link_libraries(DiffrTests
        ${DIFFR_UTIL}
        ${DIFFR_SUFFIXTREE}
        ${DIFFR_DIFF}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )
    add_test(DiffrTests DiffrTests)

    add_executable(PatchrTests
        ${DIFFR_TEST_DIR}/patch/PatchrTest.cpp
    )
    target_link_libraries(PatchrTests
        ${DIFFR_UTIL}
        ${DIFFR_PATCH}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )
    add_test(PatchrTests PatchrTests)

ENDIF()

IF("ALL" STREQUAL TESTING)

    message("-- Integration testing is enabled.")

    add_executable(IntegrationTests
        ${DIFFR_TEST_DIR}/integration/IntegrationTests.cpp
    ) 
    target_link_libraries(IntegrationTests
        ${DIFFR_UTIL}
        ${DIFFR_SUFFIXTREE}
        ${DIFFR_DIFF}
        ${DIFFR_PATCH}
        ${GLIB_LIBRARIES}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    )
    add_test(IntegrationTests IntegrationTests)

ENDIF()

add_executable (${DIFFR_DIFFNAME}
	${DIFFR_SOURCE_DIR}/diff/main.c)
target_link_libraries(${DIFFR_DIFFNAME}
	${DIFFR_UTIL}
	${DIFFR_SUFFIXTREE}
	${DIFFR_DIFF}
    ${GLIB_LIBRARIES}
)

add_executable (${DIFFR_PATCHNAME}
	${DIFFR_SOURCE_DIR}/patch/main.c)
target_link_libraries(${DIFFR_PATCHNAME}
	${DIFFR_UTIL}
	${DIFFR_PATCH}
    ${GLIB_LIBRARIES}
)
