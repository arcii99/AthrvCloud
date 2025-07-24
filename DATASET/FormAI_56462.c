//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024
#define MAX_ARGS 64

void execute_command(char* command[]) {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execvp(command[0], command);
        perror("execvp failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    } else {
        perror("fork failed");
        exit(1);
    }
}

void handle_redirect(char* command[], char* file_name, int mode) {
    int fd;
    if (mode == O_RDONLY) {
        // Input redirection
        fd = open(file_name, mode);
        if (fd < 0) {
            perror("open failed");
            exit(1);
        }
        dup2(fd, STDIN_FILENO);
    } else if (mode == O_WRONLY || mode == O_CREAT) {
        // Output redirection
        fd = open(file_name, mode, 0666);
        if (fd < 0) {
            perror("open failed");
            exit(1);
        }
        dup2(fd, STDOUT_FILENO);
    }
    command[strlen(command)-2] = NULL; // Remove '<' or '>' from argument list
    execute_command(command);
    close(fd);
}

int main() {
    char input[MAX_CMD_LENGTH];
    char* command[MAX_ARGS];
    int arg_count;
    while (1) {
        printf("> ");
        fflush(stdout);
        if (fgets(input, MAX_CMD_LENGTH, stdin) == NULL) {
            break;
        }
        arg_count = 0;
        command[arg_count] = strtok(input, " \t\n");
        while (command[arg_count] != NULL) {
            arg_count++;
            command[arg_count] = strtok(NULL, " \t\n");
        }
        if (arg_count == 0) {
            continue;
        } else if (strcmp(command[arg_count-1], "<") == 0) {
            if (arg_count >= 3) {
                handle_redirect(command, command[arg_count-2], O_RDONLY);
            } else {
                printf("Invalid input redirection.\n");
            }
        } else if (strcmp(command[arg_count-1], ">") == 0) {
            if (arg_count >= 3) {
                handle_redirect(command, command[arg_count-2], O_WRONLY|O_CREAT);
            } else {
                printf("Invalid output redirection.\n");
            }
        } else {
            execute_command(command);
        }
    }
    return 0;
}