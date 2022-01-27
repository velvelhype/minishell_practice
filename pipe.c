#include "minishell.h"

int fildes[2];

void  act_child()
{
	// write(fildes[1], "message from child\n", 20);
}

int main()
{

	pipe(fildes);

	int child = fork();
	
	if(child == 0)
	{
		act_child();
	}
	else
	{
		int status;
		wait(&status);
		char save[30];
		write(fildes[1], "hello", 5);
		read(fildes[0], save, 20);
		printf("save is :: %s\n", save);
	}
}