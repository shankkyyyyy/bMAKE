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

// this is a simple project for simple compiling of simple .c file's 
// this can be called a knockoff of CMake or Cninja 
// this will have several bugs and memory problems !! if you find one please let me know 

// defuault buffer size.
#define BUFFER_d 1024

// parsing function -> returns the system command for compiling the code
// this is read from the .CCmake file 
// the .CCmake file does not need to be in a particular order 

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
    
    printf(" %d: %s",i,buffer);
    strtok(buffer,"\n");
    printf("%s",buffer);
    i++;
    if(strcmp(buffer,"filename")==0)
    {
      if(fgets(Filename,sizeof(Filename),fp)!=NULL)
      {
        printf("%s",Filename);
        continue;
      }
      else 
      {
        printf("Compiling error at %d \n There is no filename present or NUllable character.\n",i);
        return "failed";
      }
    }
    else if (strcmp(buffer,"args")==0)
    {
      int j = 1;
      while (fgets(buffer,BUFFER_d,fp)!=NULL && strtok(buffer,"\n"))
      {
        
        if (j==1)
        {
          strcpy(args,buffer);
          printf("string worked. \n");
        }
        
        else 
        {
         strcat(args," ");
         strcat(args,buffer);
         printf("worked. \n");
        }

        printf("%d: %s",j,args);
        j++;
        printf("%d",j);

        if (strcmp(buffer,"output")==0)

        {
          
          if(fgets(outputname,buffer_d,fp)!=null) 
          {
          
            printf("all got !!\n worked perfectly.");
          
          }
          
         else   
         {
            printf("fgets returned null; ");
            return "failed";
          
         }
        }
      }

    }
    
  }

  printf("\n\n %s \n %s \n %s \n Everything data has been collected. \n\n",Filename,args,OutputName);
  free(buffer);
  free(args);

  return "passed";
}

int main()
{
  char* killi = parse("test.txt");
  printf("Everything is working properly.");
  return 0;
}
