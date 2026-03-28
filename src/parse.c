//
// made by shankky !! 

// include's 
#include <stdio.h>
// for memory allocation
#include <stdlib.h> 
// for string cutting,string manipulation's.
#include <string.h>
// for bool operations 
#include <stdbool.h>
#include "parse.h"

// this is a simple project for simple compiling of simple .c file's 
// this can be called a knockoff of CMake or Cninja 
// this will have several bugs and memory problems !! if you find one please let me know 

// defuault buffer size.
#define BUFFER_d 1024

// parsing function -> returns the system command for compiling the code
// this is read from the .CCmake file 
// the .CCmake file does not need to be in a particular order 


// checks for outputname; this function is called by args while loop.
char* output_f(char *buffer,char *OutputName,FILE *fp)
{	// reads the file
	if(fgets(buffer,BUFFER_d,fp)!=NULL)
	{
	   if(fgets(OutputName,BUFFER_d,fp)!=NULL)
	   {
		   printf("\nOutputName: %s\n",OutputName);   
	   }
	   else
	   {
	   	perror("Can't not read outputname. ");
		return "failed";
	   }
	   
	}
	// else statement for failure.
	else
	{
	  perror("Cannot read OutputName. ");
	  return "failed";
	}
	// if success; returns OutputName pointer.
	free(buffer);	
	return OutputName;
       
}

int end(char *Filename,char *args,char *OutputName)
{
	printf("Filename: %s \n args: %s \n OutputName: %s \n",Filename,args,OutputName);
	free(Filename);
	free(args);
	free(OutputName);
	return 0;
}



char* parse(char* filename)
{
  // declaration of variables related to parsing; line 43 to see the use's of this 
  char *args = malloc(BUFFER_d);
  char *buffer = malloc(BUFFER_d);
  char *Filename = malloc(BUFFER_d);
  char *OutputName = malloc(BUFFER_d);

  // this opens a file discriptor for opeing the file 
  FILE *fp = fopen(filename,"r");
  // fp returns NULL if the fopen has failed. see docs on this. 
  if (fp==NULL)
  {
    // strerr.
    printf("File can't be opened. \n");
    // 'failed' is the char* for return 1;
    return "failed";
  }

  // i is the increment for the while loop; BAD PRACTICE.
  int i = 1;
  // loop for getting the first line or the contination of lines in the file; to know more read man fgets; 
  while(fgets(buffer,BUFFER_d,fp)!=NULL)
  {
    // this removes newline from buffer.
    strtok(buffer,"\n");
    // inc the while loop;
    i++;

    // checks if buffer==filename
    if(strcmp(buffer,"filename")==0)
    {
      // reads filename if it is not null
      if(fgets(Filename,sizeof(Filename),fp)!=NULL)
      {
	// prints filename - remove this line !! debugging purpose only.
	// restarts the while loop;
        continue;
      }
      // if reading goes to fault this will end up printing error messages.
      else 
      {
        printf("Compiling error at %d \n There is no filename present or NUllable character.\n",i);
        return "failed";
      }

    }
    // checks if buffer == args 
    else if (strcmp(buffer,"args")==0)
    {
     // new incrementer is placed
      int j = 1;
      // reads the file and puts the output into buffer if not null and removes the buffer's newline 
      // all in the while loop.
      while (fgets(buffer,BUFFER_d,fp)!=NULL && strtok(buffer,"\n"))
      {

        // j is for first time copying values into buffer. then no need for the strcpy function.
        if (j==1)
        {
          strcpy(args,buffer);
	  j++;
	  continue;
        }

	if (strcmp(buffer,"endhl")==0)
	{
	   
	  OutputName =  output_f(buffer,OutputName,fp);
	  // buffer's allocated memory has been free'ed from function-> output_f;
	  int a = end(Filename,args,OutputName);
	  return "success";
	}

        // this is for concateing the strings together after the first copying into buffer.
        else if (!j==0)
	{
	// add space to args
	 strcat(args," ");
	 // concatenate the buffer to args
         strcat(args,buffer);
		 
	 // prints the args 
        }
	// increments j by 1;
      }

    }
    
  }
  return "passed";
}

