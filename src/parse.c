#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "parse.h"
#define BUFFER 1024

typedef struct FILE_INIT
{
	char *buffer;
	char *arguments;
	char *output_filename;
	char *filename;
	char *output; 

}FILE_INIT;

char *parse_filename(FILE *fp)
{
	FILE_INIT file;
	file.filename = malloc(BUFFER);
	if (file.filename==NULL)
	{
		perror("Cannot allocate memory \n");
		return NULL;
	}
	
	if(fgets(file.filename,BUFFER,fp)!=NULL)
	{
		return file.filename;	
	}
	
	else
	{
		return NULL;
	}
}

char *parse_args(FILE *fp,FILE_INIT *file)
{
	bool time = true;
	file->buffer = malloc(BUFFER);
	while(fgets(file->buffer,BUFFER,fp)!=NULL)
	{
	    strtok(file->buffer,"\n");
	    if(strcmp(file->buffer,"[ENDOFARGUMENTS]")==0)
	    {
		free(file->buffer);
		return file->arguments;
	    }
	    
            else
	    {
		if(time)
		{
			strncpy(file->arguments,file->buffer,BUFFER - 1);
			time = false;
		}
		
		else
		{
			strcat(file->arguments," ");
			strcat(file->arguments,file->buffer);
		}
	    }
	}

}

char *parse_outputfilename(FILE *fp,FILE_INIT *file)
{
	if(fgets(file->output_filename,BUFFER,fp)!=NULL)
	{
		return file->output_filename;
	}
	
	else
	{
		perror("Cannot read from File. \n");
		return NULL;
	}
	
}

char *parse(char *filename)
{	
	FILE_INIT file_init;
	file_init.buffer = malloc(BUFFER);
	file_init.output_filename = malloc(BUFFER);
	FILE *fp = fopen(filename,"r");
	if (fp==NULL)
	{
		perror("Cannot open file. ");
		return NULL;
	}
	file_init.filename = malloc(BUFFER);
	while(fgets(file_init.buffer,BUFFER,fp)!=NULL)
	  {	
	    strtok(file_init.buffer,"\n");
		if(strcmp(file_init.buffer,"[FILENAME]")==0)
		  {
		   file_init.filename = parse_filename(fp);
	    	   strtok(file_init.filename,"\n");   
                   if(file_init.filename==NULL)
		     {
		       return NULL;
		     }  
		
		   else
		      {
		      }
		  }
		else if (strcmp(file_init.buffer,"[ARGUMENTS]")==0)
			{
			  file_init.arguments = malloc(BUFFER);
			  file_init.arguments = parse_args(fp,&file_init);
			}

		else if (strcmp(file_init.buffer,"[OUTPUT]")==0)
			{
			  file_init.output_filename = parse_outputfilename(fp,&file_init);
			  if(file_init.output_filename==NULL)
			    {
				perror("Returned NULL. \n");
				return NULL;
			    }
			
			}
	
	  }
	

	file_init.output = malloc(BUFFER * 2);
	snprintf(file_init.output, BUFFER * 2, "%s %s %s", 
		     file_init.filename, 
             file_init.arguments, 
             file_init.output_filename);
	
  free(file_init.arguments);
  free(file_init.filename);
  free(file_init.output_filename);
  free(file_init.buffer);
	return file_init.output;
}

