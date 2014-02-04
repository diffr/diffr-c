/**
 * @file ArgumentsProcessorTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @since 0.0
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

#include <string.h>

#include "gtest/gtest.h"

extern "C" {
#include "diffr/util/ArgumentsProcessor.h"
}

namespace {

  /**
   * Tests ArgumentsProcessor.
   * 
   */
  class ArgumentsProcessorTest : public ::testing::Test {
  protected:

    ArgumentsProcessorTest() {

    }

    virtual ~ArgumentsProcessorTest() {

    }

  };
};

/*
 * Tests whether the containsHelpArgument function works correctly.
 * 
 */
TEST_F(ArgumentsProcessorTest, ContainsHelpArgumentTest) {
  char** arguments = (char**) malloc(5 * sizeof (char*));
  for (int i = 0; i < 5; i++) {
    arguments[i] = (char*) malloc(14 * sizeof (char));
  }
  strcpy(arguments[0], "--help");
  EXPECT_TRUE(containsHelpArgument(1, arguments));

  strcpy(arguments[0], "-help");
  EXPECT_TRUE(containsHelpArgument(1, arguments));

  strcpy(arguments[0], "--nelp");
  EXPECT_FALSE(containsHelpArgument(1, arguments));

  strcpy(arguments[0], "-nelp");
  EXPECT_FALSE(containsHelpArgument(1, arguments));

  strcpy(arguments[0], "i");
  strcpy(arguments[1], "don't");
  strcpy(arguments[2], "want");
  strcpy(arguments[3], "--help");
  strcpy(arguments[4], "");
  EXPECT_TRUE(containsHelpArgument(5, arguments));

  strcpy(arguments[0], "i");
  strcpy(arguments[1], "don't");
  strcpy(arguments[2], "want");
  strcpy(arguments[3], "-help");
  strcpy(arguments[4], "");
  EXPECT_TRUE(containsHelpArgument(5, arguments));

  strcpy(arguments[0], "i");
  strcpy(arguments[1], "don't");
  strcpy(arguments[2], "want");
  strcpy(arguments[3], "--helphrthjrhj");
  strcpy(arguments[4], "");
  EXPECT_FALSE(containsHelpArgument(5, arguments));

  strcpy(arguments[0], "i");
  strcpy(arguments[1], "don't");
  strcpy(arguments[2], "want");
  strcpy(arguments[3], "rherh-help");
  strcpy(arguments[4], "");
  EXPECT_FALSE(containsHelpArgument(5, arguments));

  for (int i = 0; i < 5; i++) {
    free(arguments[i]);
  }
  free(arguments);
}

/*
 * Tests whether the extractOutputFile function works correctly.
 * 
 */
TEST_F(ArgumentsProcessorTest, ExtractOutputFileTest) {
  char** arguments = (char**) malloc(5 * sizeof (char*));
  for (int i = 0; i < 5; i++) {
    arguments[i] = (char*) malloc(14 * sizeof (char));
  }
  strcpy(arguments[0], "-o");
  EXPECT_EQ(NULL, extractOutputFile(1, arguments));

  strcpy(arguments[0], "output");
  EXPECT_EQ(NULL, extractOutputFile(1, arguments));

  strcpy(arguments[0], "outputhere");
  EXPECT_EQ(NULL, extractOutputFile(1, arguments));

  strcpy(arguments[0], "-o dir");
  EXPECT_EQ(NULL, extractOutputFile(1, arguments));

  strcpy(arguments[0], "i");
  strcpy(arguments[1], "-o");
  strcpy(arguments[2], "want");
  strcpy(arguments[3], "output");
  strcpy(arguments[4], "here");
  EXPECT_STREQ("want", extractOutputFile(5, arguments));

  strcpy(arguments[0], "i");
  strcpy(arguments[1], "don't");
  strcpy(arguments[2], "want");
  strcpy(arguments[3], "-help");
  strcpy(arguments[4], "-o");
  EXPECT_EQ(NULL, extractOutputFile(5, arguments));

  strcpy(arguments[0], "i");
  strcpy(arguments[1], "don't");
  strcpy(arguments[2], "want");
  strcpy(arguments[3], "--helphrthjrhj");
  strcpy(arguments[4], "-o-o");
  EXPECT_EQ(NULL, extractOutputFile(5, arguments));

  strcpy(arguments[0], "-o");
  strcpy(arguments[1], "output");
  strcpy(arguments[2], "-o");
  strcpy(arguments[3], "rherh-help");
  strcpy(arguments[4], "");
  EXPECT_STREQ("output", extractOutputFile(5, arguments));

  for (int i = 0; i < 5; i++) {
    free(arguments[i]);
  }
  free(arguments);
}
