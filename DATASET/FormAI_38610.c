//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char *args[MAX_ARGS];
    int stat_loc;
    pid_t pid;

    while(1) {
        printf(">> ");
        fgets(input, MAX_LENGTH, stdin);

        // remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // tokenize the input string by space
        char *token = strtok(input, " ");
        int i = 0;
        while(token != NULL) {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL; // null terminate the array of arguments

        pid = fork();
        if(pid == -1) {
            perror("forking child process failed");
            exit(EXIT_FAILURE);
        }

        if(pid == 0) {
            // child process 
            int result = execvp(args[0], args);
            if(result == -1) {
                printf("command not found\n");
            }
            exit(EXIT_FAILURE);
        } else {
            // parent process 
            waitpid(pid, &stat_loc, WUNTRACED);
        }
    }

    return 0;
}