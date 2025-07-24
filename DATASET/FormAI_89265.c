//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: irregular
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 10

int main()
{
    char input[1024];
    char *args[MAX_ARGS];
    int status;

    while(1) {
        printf("myShell$ ");
        fgets(input, 1024, stdin);

        char *token = strtok(input, " \n");

        int i = 0;
        while (token != NULL && i < MAX_ARGS-1) {
            args[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
        else {
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}