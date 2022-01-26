#include "minishell.h"

void	do_child(void)
{
	printf("Child scream : pid=%d\n", getpid());
	exit(2);
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
		// if (wait(&status) < 0)
		if (waitpid(child, &status, WNOHANG) < 0)
		{
			perror("wait");
			exit(1);
		}
		printf("in %d child %d exit : %d\n", getpid(),
		 child, WEXITSTATUS(status));
	}
}

// https://www.coins.tsukuba.ac.jp/~syspro/2020/2020-05-27/index.html