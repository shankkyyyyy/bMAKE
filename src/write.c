#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/write.h"
#include "../include/read.h"

// Appends text content to a file
int write_to_file(char* text_content, char* file_path)
{
  FILE *file_pointer = fopen(file_path, "a");
  if (file_pointer == NULL)
  {
    printf("File pointer can't be initialised.\n");
      return 1;
  }
  
  // always append newline for clear file block layout
  int write_result = fprintf(file_pointer, "%s\n", text_content);
  fflush(file_pointer);
  fclose(file_pointer);
  
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

// Creates a build configuration file from command arguments
int config_BMake(char *source_file,char* output_file,char* flags,int NumOfFlags)
{
  int file_exists_result = file_exists(".Bmake.txt");
  if(file_exists_result == 0)
  {
    printf("There is already a Bmake config file. Do you want to overwrite it? (y/n) \n");
    char user_input[10];
    scanf("%s", user_input);
    if(strcmp(user_input, "y") == 0)
    {      remove(".Bmake.txt");
    }
    else
    {      printf("Aborting. Please remove the existing .Bmake.txt file if you want to create a new one.\n");
      return 1;  
  } 

	write_to_file("[FILENAME]",".Bmake.txt");
  write_to_file(source_file,".Bmake.txt");
  write_to_file("[ARGUMENTS]",".Bmake.txt");

  // Write each token in flags to its own line
  char flags_copy[1024];

  strncpy(flags_copy, flags, sizeof(flags_copy) - 1);
  // Ensure null termination
  flags_copy[sizeof(flags_copy) - 1] = '\0';
  // -llls -sdl -one 
  char *token = strtok(flags_copy, " ");

  while (token != NULL) {
    write_to_file(token, ".Bmake.txt");
    token = strtok(NULL, " ");
  }

  write_to_file("[ENDOFARGUMENTS]",".Bmake.txt");
  write_to_file("[OUTPUT]",".Bmake.txt");
  write_to_file(output_file,".Bmake.txt");
	return 0;
}

}
