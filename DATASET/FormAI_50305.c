//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 256

void read_command(char* command, char** arguments) {
    char* token = strtok(command, " ");
    int i = 0;
    while (token != NULL) {
        arguments[i++] = token;
        token = strtok(NULL, " ");
    }
    arguments[i] = NULL;
}

int execute_command(char** arguments) {
    pid_t childPid;
    int status;
    childPid = fork();
    if (childPid == 0) {
        execvp(arguments[0], arguments);
        fprintf(stderr, "Error: command not found\n");
        exit(1);
    } else if (childPid == -1) {
        perror("fork");
        exit(1);
    } else {
        do {
            waitpid(childPid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        return WEXITSTATUS(status);
    }
}

int main() {
    char command_buffer[BUFFER_SIZE];
    char* arguments[BUFFER_SIZE];
    int status;
    do {
        printf(">> ");
        fgets(command_buffer, BUFFER_SIZE, stdin);
        command_buffer[strcspn(command_buffer, "\n")] = 0;

        if (strlen(command_buffer) == 0) {
            continue;
        }

        read_command(command_buffer, arguments);
        status = execute_command(arguments);

    } while (status == 0);
    return 0;
}