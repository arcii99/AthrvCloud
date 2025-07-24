//FormAI DATASET v1.0 Category: System administration ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

int main() {
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character
        if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        int pid = fork();
        if (pid == -1) { // failed to fork
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // child process
            char *argv[] = {command, NULL};
            if (execvp(command, argv) == -1) { // attempt to execute the command
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            }
        } else { // parent process
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                printf("Command exited with non-zero status code %d\n", WEXITSTATUS(status));
            }
        }
    }
    return 0;
}