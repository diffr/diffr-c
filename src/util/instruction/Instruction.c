/**
 * @file Instruction.c
 * @author Amaury Couste <ben@bantertrain.com>
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

instruction* 
create_copy_instruction(long start, long end) 
{
  instruction* i = malloc(sizeof(instruction));
  memset(i, 0, sizeof(instruction));
  i->start = start;
  i->end = end;
  i->type = COPY;
  return i;
}

instruction* 
create_insert_instruction(GString* text) 
{
  instruction* i = malloc(sizeof(instruction));
  memset(i, 0, sizeof(instruction));
  i->text = g_string_new(text->str);
  i->type = INSERT;
  return i;
}

void 
delete_instruction(instruction* i)
{
  if (i->text)
    g_free(i->text);
  
  free(i);
}
