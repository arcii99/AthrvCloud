//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main() {
    char command[100];
    char *args[10];
    pid_t pid;
    int status;

    printf("Welcome to Curious Shell!\n");

    while(1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command)-1] = '\0'; // removing trailing newline

        if(strcmp(command, "exit") == 0) {
            printf("Have a curious day!\n");
            exit(0);
        }

        int i = 0;
        char *token = strtok(command, " ");
        while(token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid = fork();
        if(pid == 0) { // child process
            printf("Executing curious command: %s\n", args[0]);
            execvp(args[0], args);
            printf("Curious command execution failed!\n");
            exit(1);
        } else if(pid > 0) { // parent process
            waitpid(pid, &status, 0);
            printf("Curious command executed with status %d\n", status);
        } else { // fork failed
            printf("Curious command execution failed!\n");
            exit(1);
        }
    }

    return 0;
}