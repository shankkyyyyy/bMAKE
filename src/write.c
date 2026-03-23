#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


int WriteToFile_i(char* content,char* filename)
{
  FILE *fp = fopen(filename,"a");
  if (fp==NULL)
  {
    printf("File pointer can't be initialised.\n");
      return 1;
  }
  
  int OutputFromWriting = fprintf(fp,content);
  
  if (OutputFromWriting<0)
  {
    printf("Can't not write to the given file.\n");
    return 1;
  }
  else 
  { 
    printf("Written to file.\n");
    return 0;
  }
}

int main()
{
  int output = WriteToFile_i("Does this append the text given ?\n","given.txt");
  if (output==1)
  {
    printf("Something has fallen. \n");
    return 1;
  }
  else{
    printf("Everything went smoothly.\n");
    return 0;
  }
  
}
