//FormAI DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LEN 1024

int main() {
    char command[MAX_COMMAND_LEN];
    while(1) {
        printf("Enter command to execute: ");
        fgets(command, MAX_COMMAND_LEN, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character

        pid_t pid = fork();
        if(pid == -1) {
            perror("Error forking process");
            exit(EXIT_FAILURE);
        } else if(pid == 0) { // child process
            printf("Executing command: %s\n", command);

            // break down command into tokens
            char* tokens[MAX_COMMAND_LEN];
            char* token = strtok(command, " ");
            int i = 0;
            while(token != NULL) {
                tokens[i++] = token;
                token = strtok(NULL, " ");
            }
            tokens[i] = NULL;

            // execute command
            execvp(tokens[0], tokens);
            perror("Error executing command");
            exit(EXIT_FAILURE);
        } else { // parent process
            int status;
            waitpid(pid, &status, 0);
            printf("Command completed with exit status %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}