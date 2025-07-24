//FormAI DATASET v1.0 Category: System administration ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    char input[BUFFER_SIZE];
    char *args[100];
    int status;

    while(1) {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strlen(input)-1] = '\0';

        char *token = strtok(input, " ");
        int i = 0;
        while(token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if(strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        pid_t pid = fork();
        if(pid == 0) {
            if(execvp(args[0], args) < 0) {
                printf("Error: command not found\n");
            }
            exit(0);
        }
        else {
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}