#include "minishell.h"

extern char **environ;

// int main()
// {
// 	char *argv[2];

// 	argv[0] = "/bin/ls";
// 	// argv[1] = NULL;

// 	execve(argv[0], argv, environ);

// 	return (1);
// }

int main()
{
	char *argv[3];

	argv[0] = "ls";
	argv[1] = "-lta";
	argv[2] = NULL;

	execve("/bin/ls", argv, environ);
	return 1;
}