/**
 * @file DiffrTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This file is part of tmte-cpp.
 * 
 * tmte-cpp is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * tmte-cpp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with tmte-cpp.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "gtest/gtest.h"

extern "C" {
#include "diffr/diff/Diffr.h"
}

namespace {

    /**
     * Tests Diffr.
     * 
     */
    class DiffrTest : public ::testing::Test {
    protected:

        DiffrTest() {

        }

        virtual ~DiffrTest() {

        }

    };
};

/*
 * Tests whether the buildList method works correctly.
 * 
 */
TEST_F(DiffrTest, BuildListTest) {
    buildList();
}
