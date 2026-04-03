#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "../include/write.h"
#include "../include/read.h"
#define BUFFER_ 512
// Appends text content to a file
int write_to_file(char* text_content, char* file_path)
{
  FILE *file_pointer = fopen(file_path, "a");
  if (file_pointer == NULL)
  {
    printf("ERROR: cannot open '%s' for append.\n", file_path);
      return 1;
  }
  
  // always append newline for clear file block layout
  int write_result = fprintf(file_pointer, "%s\n", text_content);
  fflush(file_pointer);
  fclose(file_pointer);
  
  if (write_result < 0)
  {
    printf("ERROR: write failed for '%s'.\n", file_path);
    return 1;
  }
  else 
  { 
    printf("INFO: appended '%s' to '%s'.\n", text_content, file_path);
    return 0;
  }
}

// Creates a build configuration file from command arguments
int config_BMake(char *source_file,char* output_file,char* flags,int NumOfFlags)
{
  int file_exists_result = file_exists(".Bmake.txt");
  if(file_exists_result == 0)
  {
    printf("WARNING: .Bmake.txt already exists, overwrite? (y/n) ");
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

int write_args(char *args,char *filename)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("ERROR: cannot open '%s' for read.\n", filename);
    return 1;
  }

  FILE *tmp = fopen(".Bmake.tmp", "w");
  if (tmp == NULL)
  {
    printf("ERROR: cannot open temporary file for write.\n");
    fclose(fp);
    return 1;
  }

  char line[BUFFER_];
  int line_count = 0;

  // copy first three lines to temp
  while (line_count < 3 && fgets(line, sizeof(line), fp) != NULL)
  {
    fputs(line, tmp);
    line_count++;
  }

  // write args after first three lines
  fprintf(tmp, "%s\n", args);

  // copy remaining file content
  while (fgets(line, sizeof(line), fp) != NULL)
  {
    fputs(line, tmp);
  }

  fclose(fp);
  fclose(tmp);

  // replace original with temporary file
  if (remove(filename) != 0 || rename(".Bmake.tmp", filename) != 0)
  {
    printf("ERROR: could not replace '%s' with updated content.\n", filename);
    return 1;
  }

  return 0;
}