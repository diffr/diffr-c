/**
 * @file Instruction.c
 * @author Amaury Couste <ben@bantertrain.com>
 * @author Jakub Dominik Kozlowski <mail@jakub-kozlowski.com>
 * @since 0.1
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

#include "diffr/util/instruction/Instruction.h"
#include <glib-2.0/glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

instruction* 
create_copy_instruction(const long start, const long end) 
{
  const instruction iStack = {.start = start, 
                              .end = end, 
                              .type = COPY, 
                              .text = NULL
  };
  const instruction* iHeap = g_new0(instruction, 1);
  memcpy(iHeap, &iStack, sizeof(instruction));
  return iHeap;
}

instruction* 
create_insert_instruction(const GString* text) 
{
  const instruction iStack = {.start = -1, 
                              .end = -1, 
                              .type = INSERT, 
                              .text = g_string_new(text->str)
  };
  const instruction* iHeap = g_new0(instruction, 1);
  memcpy(iHeap, &iStack, sizeof(instruction));
  return iHeap;
}

void 
delete_instruction(const instruction* i)
{
  if (INSERT == i->type && NULL != i->text)
    g_string_free(i->text, TRUE);
  
  free(i);
}
