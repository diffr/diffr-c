/**
 * @file ArgumentsProcessor.h
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

#ifndef ARGUMENTSPROCESSOR_H
#define	ARGUMENTSPROCESSOR_H

#include <stdbool.h>

/**
 * Checks if the given arguments contain a call for help.
 * 
 * @param noArguments the number of arguments.
 * @param arguments the arguments to check for help.
 * @return true if the given arguments contain a call for help, 
 * false otherwise.
 */
bool containsHelpArgument(int noArguments, char** arguments);

/**
 * Extract the output file location from the given arguments.
 *
 * @param noArguments the number of arguments.
 * @param arguments the arguments to extract the output file location from.
 * @return the output file location from the given arguments.
 */
char* extractOutputFile(int noArguments, char** arguments);

#endif	/* ARGUMENTSPROCESSOR_H */
