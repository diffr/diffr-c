/**
 * @file SuffixTreesTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.0
 *
 * @section LICENSE
 *
 * This file is part of diffr-c.
 * 
 * diffr-c is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * diffr-c is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with diffr-c.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SuffixTreesTest
#include <boost/test/unit_test.hpp>

extern "C" {
#include "diffr/suffixtree/SuffixTrees.h"
}

/*
 * Tests whether the createTree method works correctly.
 * 
 */
BOOST_AUTO_TEST_CASE(CreateTreeTest) {
  createTree();
}
