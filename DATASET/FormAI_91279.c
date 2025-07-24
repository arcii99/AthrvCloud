//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64
#define MAX_PATH_LENGTH 1024

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGS];
    char *path;
    char full_path[MAX_PATH_LENGTH];
    int status;

    while (1) {
        printf("$ ");

        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // remove newline character

        if (strcmp(command, "exit") == 0) {
            exit(0);
        }

        int arg_count = 0;
        args[arg_count] = strtok(command, " ");

        while (args[arg_count] != NULL && arg_count < MAX_ARGS - 1) {
            arg_count++;
            args[arg_count] = strtok(NULL, " ");
        }

        args[arg_count] = NULL; // set last argument to NULL

        path = getenv("PATH");
        char *dir = strtok(path, ":");

        while (dir != NULL) {
            snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", dir, args[0]);
            if (access(full_path, X_OK) == 0) {
                break;
            }
            dir = strtok(NULL, ":");
        }

        if (dir == NULL) {
            printf("Command not found: %s\n", args[0]);
            continue;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execv(full_path, args);
            printf("Error executing command: %s\n", args[0]);
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }
    return 0;
}