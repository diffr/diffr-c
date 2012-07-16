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
 * Defines an ::instruction.
 *  
 */
typedef struct {
  const enum instruction_type type;
  const long start;
  const long end;
  const GString *text;
} instruction;

/**
 * Creates a ::COPY ::instruction that starts at line \a start 
 * and ends at line \a end.
 * 
 * @param start start line of the ::COPY ::instruction.
 * @param end   end line of the ::COPY ::instruction.
 * 
 * @return pointer to a newly created ::COPY ::instruction.
 */
instruction* create_copy_instruction(const long start, const long end);

/**
 * Creates an ::INSERT ::instruction that inserts \a text.
 * 
 * @param text  line to insert. This constructor creates a private copy of 
 *              \a line, therefore it is the responsibility of the caller 
 *              to free the original \a text accordingly.
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
