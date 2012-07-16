/**
 * @file Instruction.h
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
 * @section DESCRIPTION
 * 
 * Instruction's definitions.
 * 
 */

#ifndef INSTRUCTION_H
#define	INSTRUCTION_H

#include <glib-2.0/glib.h>

/**
 * Defines the type of the ::instruction.
 * 
 */
enum instruction_type {
  
  /**
   * Denotes a copy instruction.
   */
  COPY,

  /**
   * Denotes an insert instruction.
   */
  INSERT
};

/**
 * Defines a range for the ::COPY instruction that starts at 
 * \a start (inclusive) and ends at \a end (exclusive).
 * 
 */
typedef struct {
  const long start;
  const long end;
} copy_range;

/**
 * Defines an ::instruction.
 *  
 */
typedef struct {
  
  const enum instruction_type type;
  
  union {
    const copy_range *range;
    const GString *text;
  } data;
  
} instruction;

/**
 * Creates a ::COPY ::instruction for this \a range. If \a range is NULL, 
 * this function call will fail. 
 * 
 * @param range range of this ::COPY ::instruction. This constructor creates a 
 *              private copy of \a range.
 * 
 * @return pointer to a newly created ::COPY ::instruction.
 */
instruction* create_copy_instruction(const copy_range* range);

/**
 * Creates an ::INSERT ::instruction that inserts \a text. If \a text is NULL 
 * or empty, this function call will fail.
 * 
 * @param text  line to insert. This constructor creates a private copy of 
 *              \a line.
 * 
 * @return pointer to a newly created ::INSERT ::instruction.
 */
instruction* create_insert_instruction(const GString* text);

/**
 * Frees the memory pointed to by \a i.
 * 
 * @param i  instruction to free.
 */
void delete_instruction(const instruction* i);

#endif	/* INSTRUCTION_H */
