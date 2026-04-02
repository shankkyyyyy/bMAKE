#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/parse.h"
#define BUFFER_SIZE 1024

char *parse_source_filename(FILE *input_file)
{
	BuildFileInfo file_info;
	file_info.source_file_name = malloc(BUFFER_SIZE);
	if (file_info.source_file_name == NULL)
	{
		perror("Cannot allocate memory \n");
		return NULL;
	}
	
	if(fgets(file_info.source_file_name, BUFFER_SIZE, input_file) != NULL)
	{
		return file_info.source_file_name;	
	}
	
	else
	{
		return NULL;
	}
}

char *parse_command_arguments(FILE *input_file, BuildFileInfo *file_info)
{
	bool is_first_argument = true;
	file_info->input_buffer = malloc(BUFFER_SIZE);
	while(fgets(file_info->input_buffer, BUFFER_SIZE, input_file) != NULL)
	{
	    strtok(file_info->input_buffer, "\n");
	    if(strcmp(file_info->input_buffer, "[ENDOFARGUMENTS]") == 0)
	    {
		free(file_info->input_buffer);
		return file_info->command_arguments;
	    }
	    
            else
	    {
		if(is_first_argument)
		{
			strncpy(file_info->command_arguments, file_info->input_buffer, BUFFER_SIZE - 1);
			is_first_argument = false;
		}
		
		else
		{
			strcat(file_info->command_arguments, " ");
			strcat(file_info->command_arguments, file_info->input_buffer);
		}
	    }
	}

}

char *parse_output_file_name(FILE *input_file, BuildFileInfo *file_info)
{
	if(fgets(file_info->output_file_name, BUFFER_SIZE, input_file) != NULL)
	{
		return file_info->output_file_name;
	}
	
	else
	{
		perror("Cannot read from File. \n");
		return NULL;
	}
	
}

char *parse_build_file(char *file_path)
{	
	BuildFileInfo file_info;
	file_info.input_buffer = malloc(BUFFER_SIZE);
	file_info.output_file_name = malloc(BUFFER_SIZE);
	FILE *input_file = fopen(file_path, "r");
	if (input_file == NULL)
	{
		perror("Cannot open file. ");
		return NULL;
	}
	file_info.source_file_name = malloc(BUFFER_SIZE);
	while(fgets(file_info.input_buffer, BUFFER_SIZE, input_file) != NULL)
	  {	
	    strtok(file_info.input_buffer, "\n");
		if(strcmp(file_info.input_buffer, "[FILENAME]") == 0)
		{
		  file_info.source_file_name = parse_source_filename(input_file);
	    	   strtok(file_info.source_file_name, "\n");   
                   if(file_info.source_file_name == NULL)
		     {
		       return NULL;
		     }  
		
		   else
		      {
		      }
		  }
		else if (strcmp(file_info.input_buffer, "[ARGUMENTS]") == 0)
			{
			  file_info.command_arguments = malloc(BUFFER_SIZE);
			  file_info.command_arguments = parse_command_arguments(input_file, &file_info);
			}

		else if (strcmp(file_info.input_buffer, "[OUTPUT]") == 0)
			{
			  file_info.output_file_name = parse_output_file_name(input_file, &file_info);
			  if(file_info.output_file_name == NULL)
			    {
				perror("Returned NULL. \n");
				return NULL;
			    }
			
			}
	
	  }
	

	file_info.command_output = malloc(BUFFER_SIZE * 2);
	snprintf(file_info.command_output, BUFFER_SIZE * 2, "%s %s %s", 
		     file_info.source_file_name, 
             file_info.command_arguments, 
             file_info.output_file_name);
	
  free(file_info.command_arguments);
  free(file_info.source_file_name);
  free(file_info.output_file_name);
  free(file_info.input_buffer);
	return file_info.command_output;
}