/* Instructions' definitions */
#include <glib.h>

typedef struct 
{
  enum { COPY, INSERT } type;
  long start; 
  long end;
  GString *text;
} instruction;


instruction* create_copy_instruction(long start, long end);
instruction* create_insert_instruction(GString* text);

void delete_instruction(instruction* i);


