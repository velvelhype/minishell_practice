#include "minishell.h"

int main()
{
	FILE *file;
	errno = 0;
	file = fopen("hoge.txt", "r");
	if (file == NULL)
	{
		fprintf(stderr, "%d\n", errno);
		return 1;
	}
	fclose(file);
	return 0;
}