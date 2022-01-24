#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

    int main (int argc, char *argv[]) {
		char cwd[256];
		struct stat s;
		stat("/Users/kazukimori/Codes/minishell/minishell_practice/prac.c", &s);
		printf("%lld\n", s.st_size);
        return 0;
    }