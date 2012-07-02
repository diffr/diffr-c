/**
 * @file Instruction.h
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
 * @section DESCRIPTION
 * 
 * Instruction's definitions.
 * 
 */

#ifndef INSTRUCTION_H
#define	INSTRUCTION_H

#include <glib-2.0/glib.h>

typedef struct {

    enum {
        COPY, INSERT
    } type;
    long start;
    long end;
    GString *text;
} instruction;


instruction* create_copy_instruction(long start, long end);
instruction* create_insert_instruction(GString* text);

void delete_instruction(instruction* i);

#endif	/* INSTRUCTION_H */
