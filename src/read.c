#include "read.h"
#include <stdlib.h> 
#include <stdio.h> 

int Istherefile_i(char* filename)
{
  FILE *fp = fopen(filename,O_RDONLY);
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

int ReadFromFile_i(char* filename)
{
  FILE *fp = fopen(filename,O_RDONLY);
  if(fp==NULL)
  {
    printf("Cannot open file or file does not exsits.");
    return 1;
  }
  else 
  {
    char buffer[1024];
    fgets(buffer,sizeof(buffer),fp);
  }
}
