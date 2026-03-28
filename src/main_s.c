#include <stdio.h>
#include "parse.h"
#include <stdlib.h>

int main()
{
        char *finalout = parse("real.txt");
	printf("%s ",finalout);
	free(finalout);
	return 0;
}
