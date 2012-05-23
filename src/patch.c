#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instruction.h"

static void 
instructions_foreach(gpointer data, gpointer user_data)
{
  instruction *i = (instruction*) data;  
  GPtrArray *origlines = (GPtrArray*) user_data;

  if (i->type == COPY) {
    long count = i->start - 1;
    long stop = i->end - 1;

    while (count <= stop) {
      gchar *line = g_ptr_array_index(origlines, count);
      
      if (!line) {
        fprintf(stderr, "Malformed patch file, aborting!\n");
        exit(-3);
      }

      fprintf(stdout, "%s", line);
      count++;
    }
  } else if (i->type == INSERT) {
    gchar *line = i->text->str;
    ++line; // FIXME: find another way to get rid of '> '
    ++line;
    fprintf(stdout, "%s", line);
  } else {
    printf("not sure what's going on, exiting!");
    exit(-4);
  }
}

GIOChannel*
open_channel(char *filename)
{
  GIOChannel *channel = NULL;
  GError *err = NULL;
  channel = g_io_channel_new_file(filename, "r", &err);
  if (err) {
    fprintf(stderr, "Could not open file %s, aborting!\n", filename);
    exit(-1);
  }
  return channel;
}

GSList*
parse_instructions(char *filename)
{
  GIOChannel *channel = open_channel(filename);

  GString *newstr = g_string_new("dummy"); // FIXME
  gsize terminator_pos;
  
  GSList *l = NULL;
  GError *err = NULL;

  
  while (g_io_channel_read_line_string(
      channel, newstr, &terminator_pos, &err) != G_IO_STATUS_EOF) {
    instruction *i = NULL;
    if (*(newstr->str) ==  '>') {
      i = create_insert_instruction(newstr);
    } else {
      const gchar delimiter = ',';
      gchar **nums = g_strsplit(newstr->str, &delimiter, 2);
      gchar *start = *nums;
      gchar *end = *(++nums);
      
      g_strstrip(start);
      g_strstrip(end);
      
      i = create_copy_instruction((long) atoi(start), (long) atoi(end));
      g_free(start);
      g_free(end);
    }
    l = g_slist_append(l, i);
     
  }
  return l;
}

GPtrArray* 
parse_input(char *filename)
{
  GIOChannel *channel = open_channel(filename);
  GPtrArray *lines = g_ptr_array_new();
  
  GString *tmp = g_string_new("tmp"); 
  gsize terminator_pos;
  
  GError *err = NULL;
  
  while (g_io_channel_read_line_string(
      channel, tmp, &terminator_pos, &err) != G_IO_STATUS_EOF) {
    gchar *line =  g_strdup(tmp->str);
    g_ptr_array_add(lines, line);
  }
  return lines;
}

void
do_patch(GSList *instructions, GPtrArray *origlines)
{
  g_slist_foreach(instructions, instructions_foreach, origlines);
}

int 
main(int argc, char **argv)
{
  if (argc != 3) {
    fprintf(stderr, "Usage: patch <file> <patchfile>\n");
    exit(-1);
  }

  argv++;
  char *origfile = *argv;
  GPtrArray *origlines = parse_input(origfile);
  
  argv++;
  char *patchfile = *argv;
  GSList *instructions = parse_instructions(patchfile);
  do_patch(instructions, origlines);
  return 0;
}

