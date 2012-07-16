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
 * Defines an ::instruction. 
 */
typedef struct {

    enum {
        /**
         * Denotes a copy instruction.
         */
        COPY, 
        
        /**
         * Denotes an insert instruction.
         */
        INSERT
    } type;
    
    const long start;
    const long end;
    const GString *text;
} instruction;

/**
 * Creates an \link ::type::COPY COPY \endlink that starts 
 * at line #start and ends at line #end.
 * 
 * @param start start line of the \link ::type::COPY COPY \endlink 
 *              instruction.
 * @param end   end line of the \link ::type::COPY COPY \endlink 
 *              instruction.
 * @return pointer to a newly created \link ::type::COPY COPY \endlink 
 *              instruction.
 */
instruction* create_copy_instruction(const long start, const long end);

/**
 * Creates an \link ::type::INSERT INSERT \endlink that inserts #text.
 * 
 * @param text  line to insert. The line is copied, therefore it is the 
 *              responsibility of the caller to free the original string.
 * @return pointer to a newly created \link ::type::INSERT INSERT \endlink 
 *         instruction.
 */
instruction* create_insert_instruction(const GString* text);

/**
 * Frees the memory pointed to by #i.
 * 
 * @param i  instruction to free.
 */
void delete_instruction(const instruction* i);

#endif	/* INSTRUCTION_H */
