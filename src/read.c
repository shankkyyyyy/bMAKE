// made by shankkyyyyy

#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

// function checks if there is a file named arg filename 
// function returns int -> 1 for failed and 0 for success
//
int Istherefile_i(char* filename)
{
  // opens a fd to fp 
  FILE *fp = fopen(filename,"r");
  // returns NULL if failed
  
  if(fp==NULL)
  	return 1; // error handling must be done by the called of this function.
  else 
        return 0;
}

// this function reads from the arg filename
// this returns a pointer char 
// returns the whole fileoutput 

char* ReadFromFile_pC(char* filename)
{
  // opens a fd -> fp.
  
  
  FILE *fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("Cannot open file or file does not exsits.");
    return NULL;
  }
  else 
  {
    char *ReadOutput = malloc(sizeof(char)*100);
    char buffer[1024];
    int i = 0;
    while(fgets(buffer,sizeof(buffer),fp)!=NULL)
    {
      if(i==0)
      {
        strcpy(ReadOutput,buffer);
        i++;
      }
      else{
        strcat(ReadOutput,buffer);
      }
      printf("-Read from file is successful.\n");
    }

    free(fp);
    return ReadOutput;
  }
}

int main()
{
  char *o_RfromFile = ReadFromFile_i("test.txt");
  if (strcmp("Error code 24.",o_RfromFile)==0)
  {
    printf("Error Code 24.");
    return 1;
  }
  else{
    printf("%s",o_RfromFile);
    free(o_RfromFile);
    return 0;
  }
}
