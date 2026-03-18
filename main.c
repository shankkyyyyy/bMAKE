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

  }

  return 0;
}
