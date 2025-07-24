//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char input[100];
    char *arguments[20];
    pid_t pid;
    int status;

    printf("Welcome to Visionary Shell!\n");

    while(1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';   // remove trailing \n character from input

        // if user enters "exit", exit the shell
        if(strcmp(input, "exit") == 0) {
            printf("Exiting Visionary Shell...\n");
            break;
        }

        // split input string into individual arguments
        char *arg = strtok(input, " ");
        int i = 0;
        while(arg != NULL) {
            arguments[i] = arg;
            i++;
            arg = strtok(NULL, " ");
        }
        arguments[i] = NULL;

        // create child process to execute command
        pid = fork();

        if(pid < 0) {
            printf("Error: Unable to create child process.\n");
            exit(1);
        }
        else if(pid == 0) {
            // child process
            if(execvp(arguments[0], arguments) < 0) {
                printf("Error: Unable to execute command.\n");
                exit(1);
            }
        }
        else {
            // parent process
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}