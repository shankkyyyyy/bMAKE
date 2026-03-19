#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h> 

int main(int argc,char** argv)
{
  // if there are no flags 
  if(argc==2){
    // declaration of delim 
    const char *delim = ".";
    // declaration of program name 
    char *ProgramName = argv[1];
    // printing to stdout 
    printf("[#] Compiling %s  Using GCC [#]\n",ProgramName);
    
    // cutting down the '.' part from ProgramName for the output Name 
    char *NameOfTheProgram = strtok(ProgramName,delim);
    // simply fflushing *NO REASON*
    fflush(stdout);
    char *buff; 
    
    // allocating buffer for buff 
    
    buff = malloc(100*4);
    
    // copying the strings to buffer::buff 
    strcpy(buff,"gcc ");
    strcat(buff,ProgramName);
    strcat(buff,".c ");
    strcat(buff," -o ");
    strcat(buff,NameOfTheProgram);
    fflush(stdout);
    
    // running the parsed command through system 
    system(buff);
    // freeing memory 
    free(buff);
    printf("[#] Compiled Into %s [#]\n",NameOfTheProgram);
    return 0;
  }
  // if there are flags 
  else if (argc>=3)
  {
    // declaration of variables ;
    char *ProgramName = argv[1];
    char *delim = ".";

    // parsing the output name;
    char *CompiledProgramName = strtok(ProgramName,delim);
    //allocating buffer through malloc 
    char *buffer = malloc(100*4);
    
    printf("[#] Compiling %s Using GCC [#]",ProgramName);
    // copying the gcc string into buffer after allocating memory 
    strcpy(buffer,"gcc ");
    
    // catenates argv[i] to buffer with how many flags it has !! 

    for (int i = 2;i<argc;i++)
    {
      if(strcmp(argv[i],"-w")==0)
      {
        strcat(buffer,"-Wall -Wextra ");
      }
      strcat(buffer,argv[i]);
      strcat(buffer," ");
    }
    
    // catenates hardcoded 
    strcat(buffer,ProgramName);
    strcat(buffer," -o ");
    strcat(buffer,CompiledProgramName);
    
    //executing buffer to compile the code 
    system(buffer);

    // printing the result of executing buffer 
    
    printf("[#] Compiled %s Into %s [#]",)
    // freeing buffer->compiling time needed buffer !
    free(buffer);

    return 0;

  }

  return 0;
}
