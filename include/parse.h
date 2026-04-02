#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER 1024

typedef struct FILE_INIT
{
	char *buffer;
	char *arguments;
	char *output_filename;
	char *filename;
	char *output; 

} FILE_INIT;

char *parse_filename(FILE *fp);
char *parse_args(FILE *fp, FILE_INIT *file);
char *parse_outputfilename(FILE *fp, FILE_INIT *file);
char *parse(char *filename);

#endif