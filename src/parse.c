#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

// filename 
// nameofthefile
//
// args
// wextra
// blah
// end;
// output
// output program name 
// endhl;

char* parse(char* filename)
{
  FILE *fp = fopen(filename,"r");
  if (fp==NULL)
  {
    printf("File can't be opened. \n");
    return "failed";
  }
  char* outputName = malloc( 10 * 4);
  char* args = malloc(10 * 4);
  char* buffer = malloc(10 * 4);
  char* Filename = malloc(10 * 8);
  int i = 0;
  bool FirstTimeArg = true;
  while(fgets(buffer,sizeof(buffer),fp)!=NULL)
  {
    printf("reading the data ");
    printf("%s\n\n",buffer);
    if (strcmp("filename",buffer)==0)
    {
      fgets(Filename,sizeof(Filename),fp);
      printf("%s\n\n",Filename);
      i++;  
      continue;
    }
    else if(i==1)
    {
      // right now buffer has 'args'
      while(fgets(buffer,sizeof(buffer),fp)!=NULL && strcmp(buffer,"endhl")!=0)
      {
        printf("second while loop :%s",buffer);
        if (FirstTimeArg)
        {
          strcpy(args,buffer);
          FirstTimeArg = false;
          continue;
        }

        strcat(args,buffer);
        printf("%s",args);

      }
      i++;
    }
    else if (i==2)
    {
      if(strcmp(buffer,"output")==0)
      {
        fgets(outputName,sizeof(outputName),fp);
        printf("%s",outputName);
        i++;
      }
    }

    else if (i==3)
    {
      printf("%s \n %s \n %s.\n",outputName,args,Filename);
    }


  }
   printf("%s \n %s \n %s.\n",outputName,args,Filename);

  free(args);
  free(outputName);
  free(Filename);
  return "passed";
}

int main()
{
  char* killi = parse("test.txt");
  printf("Everything is working properly.");
  return 0;
}
