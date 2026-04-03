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
            fprintf(stderr, "\033[1;31mERROR:\033[0m Could not write .Bmake.txt (config save failed).\n");
            return 1;
        }

        printf("\033[1;32mSUCCESS:\033[0m Build config saved. Run 'Bmake -s' next to compile.\n");

    }

    else if (strcmp(argv[1],"-a")==0)
    {
        printf("INFO: adding new arguments to existing .Bmake.txt\n");
        if(file_exists(".Bmake.txt") != 0)
        {
            printf("\033[1;31mERROR:\033[0m Missing .Bmake.txt; run 'Bmake -e <src> -o <out>' first.\n");
            return 1;   
        }
        
        for (int i = 2; i < argc; i++)
        {
            write_args(argv[i], ".Bmake.txt");
        }
        printf("INFO: Arguments added. Run 'Bmake -s' next to compile with new arguments.\n");
    }

    else if (strcmp(argv[1],"-s")==0)
    {
        printf("INFO: Starting build from config .Bmake.txt\n");
        if(file_exists(".Bmake.txt") != 0)
        {
            printf("\033[1;31mERROR:\033[0m Missing .Bmake.txt; run 'Bmake -e <src> -o <out>' first.\n");
        }

        char *output = parse_build_file(".Bmake.txt");
        if(output == NULL)
        {
            perror("\033[1;31mERROR:\033[0m parse_build_file failed");
            return 1;
        }

        char command[BUFFER];

        strcpy(command,output);
        free(output);
        int status = system(command);
        if(status == -1)
        {
            perror("\033[1;31mERROR:\033[0m system call failed");
            return 1;
        }
        else
        {
            printf("\033[1;32mSUCCESS:\033[0m Compilation completed (exit code %d).\n", WEXITSTATUS(status));
        }

    }

    return 0;
}

// Print a simple help menu
void print_help() {
    printf("\033[1;36mUsage:\033[0m Bmake [command] [options]\n");
    printf("\033[1;33mExample:\033[0m Bmake -e main.c -o output.elf -a ' -lcrypto -sdl'\n");
    printf("\033[1;35mCommands:\033[0m\n");
    printf("  \033[1;32m-e\033[0m <src>       Generate .Bmake.txt config\n");
    printf("  \033[1;32m-s\033[0m            Read config and build output\n");
    printf("  \033[1;32m-a\033[0m <arg>       Append one arg to ARGUMENTS section\n");
    printf("  \033[1;32mhelp\033[0m       Show this help menu\n");
}

// Execute command placeholder
void execute_command(const char *source_file, const char *output_file, const char *flags) {
    char command[BUFFER];

    // Build the system command
    snprintf(command, BUFFER, "gcc %s %s -o %s", source_file, flags, output_file);

    printf("INFO: Running build command: %s\n", command);

    int status = system(command);
    if (status == -1) {
        perror("system");
        exit(EXIT_FAILURE);
    } else {
        printf("Command executed with exit code: %d\n", WEXITSTATUS(status));
    }
}
