/**
 * @file ArgumentsProcessor.c
 * @author William Martin <will.st4@gmail.com>
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

#include <strings.h>
#include "diffr/util/ArgumentsProcessor.h"

bool containsHelpArgument(int noArguments, char** arguments) {
  for (int i = 0; i < noArguments; i++) {
    char* s = arguments[i];
    if (0 == strcasecmp(s, "--help")
            || 0 == strcasecmp(s, "-help")) {
      return true;
    }
  }
  return false;
}

char* extractOutputFile(int noArguments, char** arguments) {
  for (int i = 0; i < noArguments - 1; i++) {
    char* s = arguments[i];
    if (0 == strcasecmp(s, "-o")) {
      return arguments[i + 1];
    }
  }
  return NULL;
}
