#include "minishell.h"

int main()
{
	char *env;

	env = getenv("LANG");
	printf("got %s\n", env);
}