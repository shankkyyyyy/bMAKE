// made by shankkyyyyy

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include "../include/read.h"

// function checks if there is a file named arg filename 
// function returns int -> 1 for failed and 0 for success
//
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

// this function reads from the arg filename
// this returns a pointer char 
// returns the whole fileoutput 

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

int main()
{
  char *read_result = read_file_content("test.txt");
  if (strcmp("Error code 24.", read_result) == 0)
  {
    printf("Error Code 24.");
    return 1;
  }
  else{
    printf("%s", read_result);
    free(read_result);
    return 0;
  }
}
