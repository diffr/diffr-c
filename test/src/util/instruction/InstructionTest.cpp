/**
 * @file InstructionTest.cpp
 * @author  William Martin <will.st4@gmail.com>
 * @version 0.1
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

#include "gtest/gtest.h"

extern "C" {
#include "diffr/util/instruction/Instruction.h"
}

namespace {

    /**
     * Tests Instruction.
     * 
     */
    class InstructionTest : public ::testing::Test {
    protected:

        InstructionTest() {

        }

        virtual ~InstructionTest() {

        }

    };
};

/*
 * Tests whether the ::create_copy_instruction method works correctly.
 * 
 */
TEST_F(InstructionTest, CreateCopyInstructionTest) {
  copy_range range = {1, 2};
  instruction *const i = create_copy_instruction(&range); 
  ASSERT_EQ(i->type, COPY) << "Type is not COPY";
  ASSERT_EQ(i->data.range->start, 1) << "Start is not 1";
  ASSERT_EQ(i->data.range->end, 2) << "End is not 2";
  delete_instruction(i);
}

/*
 * Tests whether the ::create_insert_instruction method works correctly.
 * 
 */
TEST_F(InstructionTest, CreateInsertInstructionTest) {
  GString *const hello_world = g_string_new("hello world!");
  instruction *const i = create_insert_instruction(hello_world); 
  ASSERT_EQ(i->type, INSERT) << "Type is not COPY";
  ASSERT_TRUE(g_string_equal(hello_world, i->data.text)) << "text is not 'hello world!'";
  delete_instruction(i);
  g_string_free(hello_world, TRUE);
}
