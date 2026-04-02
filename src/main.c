// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "/home/gigu/projects/Bmake/include/parse.h"
//#include "/home/gigu/projects/Bmake/include/read.h"
#include "../include/write.h"

#define BUFFER 1024

// Function declarations (fill these later)
void print_help();
void execute_command(const char *source_file, const char *output_file, const char *flags);

int main(int argc, char **argv) {
    if (argc == 1 || strcmp(argv[1], "help") == 0) {
        print_help();
        return 0;
    }

    if (argc < 3) {
        fprintf(stderr, "Error: Not enough arguments.\n");
        print_help();
        return 1;
    }
    if (strcmp(argv[1],"-e")==0)
    {
        // Bmake -e main.c -lcrypto -sdl -o output 
        char *source_file = argv[2];
        char *flags = malloc(BUFFER);
        char *output_file = malloc(BUFFER);
        flags[0] = '\0';
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

        printf("source_file: %s\noutput_file: %s\nflags: %s", source_file, output_file, flags);
        
	free(flags);
        free(output_file);
        return 0;
    }
    // Extract arguments (you can expand this)
    const char *source_file = argv[1];
    const char *output_file = argv[2];
    const char *flags = (argc > 3) ? argv[3] : "";

    // Execute command placeholder
    execute_command(source_file, output_file, flags);

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
