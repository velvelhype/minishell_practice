#include "minishell.h"

int main()
{
	int fd = open("book.txt", O_RDWR);
	dup2(fd, 0);
	// close(fd);

	char save[30];
	read(0, save, 24);
	write(1, save, 24);
	// printf("henlo");
}