#include <stdio.h>
#include <string.h>

int main()
{
	char token[] = "hello how are you";
	char *wow = strtok(token," ");
	printf("%s %s",token,wow);
	wow = strtok(NULL," ");
	printf(" %s ",wow);
	return 0;
}
