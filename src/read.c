// made by shankkyyyyy

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include "../include/read.h"

// Checks if a file exists, returns 0 if exists, 1 if not
int file_exists(char* file_path)
{
  // opens a fd to fp 
  FILE *file_pointer = fopen(file_path, "r");
  // returns NULL if failed
  
  if(file_pointer == NULL)
  	return 1; // error handling must be done by the called of this function.
  else 
        return 0;
}

// Reads entire file content and returns as string
char* read_file_content(char* file_path)
{
  // opens a fd -> fp.
  
  
  FILE *file_pointer = fopen(file_path, "r");
  if(file_pointer == NULL)
  {
    printf("Cannot open file or file does not exsits.");
    return NULL;
  }
  else 
  {
    char *file_content = malloc(sizeof(char) * 100);
    char line_buffer[1024];
    int is_first_line = 0;
    // Read all lines and concatenate
    while(fgets(line_buffer, sizeof(line_buffer), file_pointer) != NULL)
    {
      if(is_first_line == 0)
      {
        strcpy(file_content, line_buffer);
        is_first_line++;
      }
      else{
        strcat(file_content, line_buffer);
      }
      printf("-Read from file is successful.\n");
    }

    free(file_pointer);
    return file_content;
  }
}


