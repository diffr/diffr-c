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

OPTION(TESTING "Build tests." ON)

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
    )
target_link_libraries (${DIFFR_UTIL}
    ${GLIB_LIBRARIES}
)

add_library (${DIFFR_SUFFIXTREE}
    ${DIFFR_SOURCE_DIR}/suffixtree/SuffixTrees.c
    )
target_link_libraries (${DIFFR_SUFFIXTREE}
    ${GLIB_LIBRARIES}
)

add_library (${DIFFR_DIFF}
    ${DIFFR_SOURCE_DIR}/diff/Diffr.c
    )
target_link_libraries (${DIFFR_DIFF}
    ${GLIB_LIBRARIES}
)

add_library (${DIFFR_PATCH}
    ${DIFFR_SOURCE_DIR}/patch/Patchr.c
    )
target_link_libraries (${DIFFR_PATCH}
    ${GLIB_LIBRARIES}
)

add_executable (${DIFFR_DIFFNAME}
	${DIFFR_SOURCE_DIR}/diff/main.c)
target_link_libraries(${DIFFR_DIFFNAME}
	${DIFFR_UTIL}
	${DIFFR_SUFFIXTREE}
	${DIFFR_DIFF})

add_executable (${DIFFR_PATCHNAME}
	${DIFFR_SOURCE_DIR}/patch/main.c)
target_link_libraries(${DIFFR_PATCHNAME}
	${DIFFR_UTIL}
	${DIFFR_PATCH})

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################

IF(TESTING)

    add_subdirectory(gtest)
    enable_testing(true)

    include_directories(
        ${gtest_SOURCE_DIR}/include 
        ${gtest_SOURCE_DIR}
    )
	
    # list test definitions here
    # TODO: replace this with a macro

    add_executable(UtilTests
	${DIFFR_TEST_DIR}/util/ArgumentsProcessorTest.cpp
    )
    target_link_libraries(UtilTests gtest gtest_main
        ${DIFFR_UTIL}
    )
    add_test(UtilTests UtilTests)

    add_executable(SuffixTreeTests
	${DIFFR_TEST_DIR}/suffixtree/SuffixTreesTest.cpp
    )
    target_link_libraries(SuffixTreeTests gtest gtest_main
        ${DIFFR_SUFFIXTREE}
    )
    add_test(SuffixTreeTests SuffixTreeTests)

    add_executable(DiffrTests
        ${DIFFR_TEST_DIR}/diff/DiffrTest.cpp
    )
    target_link_libraries(DiffrTests gtest gtest_main
        ${DIFFR_UTIL}
        ${DIFFR_SUFFIXTREE}
        ${DIFFR_DIFF})
    add_test(DiffrTests DiffrTests)

    add_executable(PatchrTests
        ${DIFFR_TEST_DIR}/patch/PatchrTest.cpp
    )
    target_link_libraries(PatchrTests gtest gtest_main
        ${DIFFR_UTIL}
        ${DIFFR_PATCH})
    add_test(PatchrTests PatchrTests)

ENDIF(TESTING)
