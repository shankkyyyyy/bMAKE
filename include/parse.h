#pragma once
#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef struct BuildFileInfo
{
	char *input_buffer;
	char *command_arguments;
	char *output_file_name;
	char *source_file_name;
	char *command_output; 

} BuildFileInfo;

char *parse_source_filename(FILE *input_file);
char *parse_command_arguments(FILE *input_file, BuildFileInfo *file_info);
char *parse_output_file_name(FILE *input_file, BuildFileInfo *file_info);
char *parse_build_file(char *file_path);

#endif