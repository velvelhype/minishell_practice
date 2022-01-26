#include "minishell.h"

int main()
{
	for (int i  = 0; i < 100; i++)
	printf("%s\n", strerror(i));
	open("hoge",O_RDONLY);
	printf("%s\n", strerror(errno));
	return 0;
}