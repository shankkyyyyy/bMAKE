#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/write.h"


int write_to_file(char* text_content, char* file_path)
{
  FILE *file_pointer = fopen(file_path, "a");
  if (file_pointer == NULL)
  {
    printf("File pointer can't be initialised.\n");
      return 1;
  }
  
  int write_result = fprintf(file_pointer, text_content);
  
  if (write_result < 0)
  {
    printf("Can't not write to the given file.\n");
    return 1;
  }
  else 
  { 
    printf("Written to file.\n");
    return 0;
  }
}

char *to_file(char *source_file,char* output_file,char* flags)
{
	printf("it is working.");
	return NULL;
}
