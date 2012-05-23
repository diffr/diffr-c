#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "instruction.h"

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
