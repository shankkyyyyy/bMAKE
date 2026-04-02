// main.c
// this is a small build system that compiles c files using gcc
// this was made by shankkyyyyy and ninefour 
// this is a small project that is meant to be a simple build system for c files.
// THIS IS NOT A BETTER PROGRAM THAN CMAKE 
// i find it hard to learn cmake so i made my own version of a build system where i can
// compile my small projects files and maintain them 
// while i use CMake for my bigger projects, this is a small project that is meant to be a simple build system for c files.

// thank you for reading. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/parse.h"
#include "../include/read.h"
#include "../include/write.h"

#define BUFFER 1024

// Function declarations (fill these later)
void print_help();
void execute_command(const char *source_file, const char *output_file, const char *flags);

// Main entry point, handles command line arguments
int main(int argc, char **argv) {
    if (argc == 1 || strcmp(argv[1], "help") == 0) {
        print_help();
        return 0;
    }
    if (strcmp(argv[1],"-e")==0)
    {
        // Bmake -e main.c -lcrypto -sdl -o output 
        char *source_file = argv[2];
        char *flags = malloc(BUFFER);
        char *output_file = malloc(BUFFER);
        flags[0] = '\0';
        int NumOfFlags = argc - 4; // Number of flags is total arguments minus the first 4 (Bmake, -e, source_file, -o)
        // Parse flags and find output file
        for(int i = 3;i<argc;i++)
        {
            if(strcmp(argv[i],"-o")==0)
            {
                strcpy(output_file,argv[i + 1]);
                break;
            }
            else 
            {
                strcat(flags, argv[i]);
                strcat(flags, " ");
            }
        }

        int result = config_BMake(source_file, output_file, flags, NumOfFlags);
        if(result != 0)
        {   
            fprintf(stderr, "Error: Failed to create .Bmake.txt file.\n");
            return 1;
        }

        printf("Bmake -s : For compiling the code.");

    }

    else if (strcmp(argv[1],"-s")==0)
    {
        printf("here.");
        if(file_exists(".Bmake.txt")!=0)
        {
            printf("print here help menu ! and explain to that guy okay.");
        }

        char *output = parse_build_file(".Bmake.txt");
        if(output==NULL)
        {
            perror("parsing.");
            return 1;
        }

        char command[BUFFER];

        strcpy(command,output);
        int status = system(command);
        if(status == -1)
        {
            perror("system");
            return 1;
        }
        else
        {
            printf("successfully compiled the file. \n");
        }

    }

    return 0;
}

// Print a simple help menu
void print_help() {
    printf("Usage: Bmake <source_file> <output_file> [flags]\n");
    printf("Example: Bmake source.c -lcrypto -o output\n");
    printf("Flags:\n");
    printf("  -l<library>   Link with library\n");
    printf("  -o<output>    Specify output file\n");
    printf("  help          Show this help menu\n");
}

// Execute command placeholder
void execute_command(const char *source_file, const char *output_file, const char *flags) {
    char command[BUFFER];

    // Build the system command
    snprintf(command, BUFFER, "gcc %s %s -o %s", source_file, flags, output_file);

    printf("Executing: %s\n", command);

    int status = system(command);
    if (status == -1) {
        perror("system");
        exit(EXIT_FAILURE);
    } else {
        printf("Command executed with exit code: %d\n", WEXITSTATUS(status));
    }
}
