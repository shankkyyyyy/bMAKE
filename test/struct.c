#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FILE_proc{
	char *buffer;
	char *args;
}FILE_FUNCS;

int main()
{
	FILE_FUNCS filess;
	filess.buffer = malloc(500);
	filess.args = malloc(450);
	
	strcpy(filess.buffer,"Hello, World.");
	strcpy(filess.args,"this is so cool tbh.");

	printf("%s \n %s \n",filess.buffer,filess.args);

	free(filess.buffer);
	free(filess.args);
}
