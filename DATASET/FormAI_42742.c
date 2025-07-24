//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

void read_command(char* command, char* args[]);
void execute_command(char* command, char* args[]);

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_ARGUMENTS];
    int status;

    while(1) {
        printf(">> ");
        read_command(command, args);
        if(strcmp(command, "exit") == 0) {
            return 0;
        }
        execute_command(command, args);
        wait(&status); // Wait for child process to exit
    }

    return 0;
}

void read_command(char* command, char* args[]) {
    char* token;
    char* delimiter = " ";
    int i = 0;

    fgets(command, MAX_COMMAND_LENGTH, stdin);
    // Remove newline character from input
    command[strcspn(command, "\n")] = 0;

    token = strtok(command, delimiter);
    while(token != NULL && i < MAX_ARGUMENTS - 1) {
        args[i++] = token;
        token = strtok(NULL, delimiter);
    }

    args[i] = NULL; // Set last argument to NULL
}

void execute_command(char* command, char* args[]) {
    pid_t pid;

    pid = fork(); // Create child process
    if(pid < 0) {
        printf("Error: fork() failed\n");
        exit(1);
    } else if(pid == 0) {
        // Child process
        if(execvp(command, args) == -1) {
            printf("Error: command not found\n");
            exit(1);
        }
    } else {
        // Parent process
        return;
    }
}