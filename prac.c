#include "minishell.h"

int main() {
    char* line;
    while (line = readline("microshell > ")) 
    { /* 行の読み取り */
        printf("Read '%s'\n", line);
        char *argv[3];
        extern char **environ;
	    chdir("/Users/kazukimori/Codes/minishell/JUNshell");
        printf("now we exec\n");
        argv[0] = "pwd";
        argv[1] = NULL;
        execve(line, argv, environ);
        if (strlen(line) > 0) {
            add_history(line); /* 履歴を保存 */
        }
        free(line);
    }
    printf("\nexit\n");
    return 0;
}