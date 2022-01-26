#include "minishell.h"

int main()
{
	// FILE *file;
	// file = fopen("hoge.txt", "r");
	open("hello", 1,  O_RDONLY);
	// kill(1, 1);
	// if (file == NULL);
	// {
	// 	fprintf(stderr, "%d %s\n", errno, strerror(errno));
	// 	return 1;
	// }
	fprintf(stderr, "%d %s\n", errno, strerror(errno));

	// fclose(file);
	return 0;
}