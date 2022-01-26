#include "minishell.h"

extern char **environ;

void do_child(void)
{
	char *argv[3];

	printf("child %d\n", getpid());
	argv[0] = "/bin/xxxx";
	argv[1] = NULL;
	if (execve(argv[0], argv, environ) < 0)
	{
		perror("execv");
		exit(11);
	}
}

int main()
{
	int child, status;
	perror("non");
	exit(2);
	if ((child = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	if	(child == 0)
	{
		do_child();
	}
	else
	{
		// if (wait(&status) < 0)
		if (waitpid(child, &status, 2) < 0)
		{
			perror(("wait"));
			exit(1);
		}
		printf("in %d child %d exited with %d\n", getpid(),
		 child, WEXITSTATUS(status));
	}
}