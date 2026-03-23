#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>

int Istherefile_i(char* filename)
{
  FILE *fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("The does not exsits.");
    return 1;
  }
  else 
  {
    return 0;
  }
}

char* ReadFromFile_i(char* filename)
{
  FILE *fp = fopen(filename,"r");
  if(fp==NULL)
  {
    printf("Cannot open file or file does not exsits.");
    return "Error code 24.";
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
