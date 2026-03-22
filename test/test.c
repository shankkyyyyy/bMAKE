#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int ReadFromFile_i(char* filename)
{
  FILE *fp = fopen(filename,"r+");
  if(fp==NULL)
  {
    printf("Cannot open file or file does not exsits.");
    return 1;
  }
  else 
  {

  char buffer[1024];
  while (fgets(buffer,sizeof(buffer),fp)!=NULL)
    {
      printf("%s",buffer);
    }
   
 
  int a = fprintf(fp,"hello world !");
  printf("%d\n",a);
  fclose(fp);

  return 0;
  }
}


int main()
{
  ReadFromFile_i("test.txt");
  return 0;
}

