#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define Default_Buffer 512

typedef struct FILE_INIT
{
   char *buffer;
   char *Filename;
   char *Arguments; 
   char *File_Output;
   char *Return_Output;
}FILE_INIT;


void *Allocate_Memory()
{
	return malloc(Default_Buffer);
}

char *parse(char* filename)
{
    FILE_INIT file_init;
    file_init.buffer = Allocate_Memory();

    file_init.Filename = Allocate_Memory();
    file_init.Arguments = Allocate_Memory();
    
    FILE *fp = fopen(filename,"r");
    if (fp==NULL)
    {
    	printf("File Descriptor Can't be opened. ");
	return NULL;
    }
    
    while(fgets(file_init.buffer,Default_Buffer,fp)!=NULL)
    {
	strtok(file_init.buffer,"\n");
    	if(strcmp(file_init.buffer,"[FILENAME]")==0)
	{
	   if(fgets(file_init.Filename,Default_Buffer,fp)!=NULL)
	   {
	   	printf("%-10s :Success\n","Filename");
		continue;
	   }
	   else
	   {
	   	printf("Can't not read [FILENAME] ");
		return NULL;
	   }
	}

	else if (strcmp(file_init.buffer,"[ARGUMENTS]")==0)
	{
	   while(fgets(file_init.buffer,Default_Buffer,fp)!=NULL)
	   {
		strtok(file_init.buffer,"\n");
		 if(strcmp(file_init.buffer,"[ENDOFARGS]")==0)
		{
		    printf("reached here.");
		    fflush(stdout);
		    if(fgets(file_init.buffer,Default_Buffer,fp)!=NULL)
		    {
		       
		       if(fgets(file_init.File_Output,Default_Buffer,fp)!=NULL);
		       {
		         printf("%-15s :Success\n","File_Output");
		         fflush(stdout);
		       }

	            }
	            else
		    {
			printf("Cannot Read the file. \n");
			return NULL;
		    }   
		}
		else{
			strcpy(file_init.Arguments," ");
			strcat(file_init.Arguments,file_init.buffer);
	   		printf("%-15s : Success\n","Arguments");
			printf("%s \n",file_init.Arguments);
		}
	   }
	    	}

	else 
	{
	    printf("%s",file_init.buffer);
	    printf("2, Syntax Error Has Happended.");
	    return NULL;
	}
    }

    file_init.Return_Output = Allocate_Memory();

    strcpy(file_init.Return_Output,file_init.Filename);
    strcat(file_init.Return_Output," ");
    strcat(file_init.Return_Output,file_init.Arguments);
    strcat(file_init.Return_Output," ");
    strcat(file_init.Return_Output,file_init.File_Output);
    
    free(file_init.File_Output);
    free(file_init.Filename);
    free(file_init.Arguments);
    return file_init.Return_Output;

}


int main()
{
	char *Final_Output = parse("test.ttxt");
	printf("%s",Final_Output);
	free(Final_Output);
}
