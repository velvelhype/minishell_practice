#include "minishell.h"

extern char **environ;

void	do_child(void)
{
	char *argv[2];

	argv[0] = "/bin/ls";
	argv[1] = NULL;
	if (execve(argv[0], argv, environ) < 0)
	{
		perror("execve");
		exit(1);
	}
}

int	main()
{
	int child;
	int status;

	if ((child = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	if (child == 0)
	{
		do_child();
	}
	else
	{
		if (wait(&status) < 0)
		{
			perror("wait");
			exit(1);
		}
		printf("child %d exit:%d\n", child, WEXITSTATUS(status));
	}
}