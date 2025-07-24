//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_ARGS 10
#define MAX_SIZE 1024

void clear_buffer(char buffer[]) {
    for (int i = 0; i < MAX_SIZE; i++) {
        buffer[i] = '\0';
    }
}

int parse_input(char input[], char* args[]) {
    clear_buffer(input);

    fgets(input, MAX_SIZE, stdin);

    if (strlen(input) == 1) {
        return 0;
    }

    input[strlen(input) - 1] = '\0'; 
    int argc = 0;
    char* token = strtok(input, " ");

    while (token != NULL && argc < MAX_ARGS) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, " ");
    }

    args[argc] = NULL; 
    return argc; 
}

int main() {
    char input[MAX_SIZE]; 
    char* args[MAX_ARGS];
    pid_t pid; 

    while (1) {
        printf(">> "); 

        int argc = parse_input(input, args);

        if (argc == 0) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            exit(0); 
        }

        pid = fork(); 

        if (pid < 0) {
            perror("Error: Failed to fork process.\n");
            exit(1); 
        } else if (pid == 0) {
            execvp(args[0], args); 
            perror("Error: Failed to execute command.\n");
            exit(1); 
        } else {
            waitpid(pid, NULL, 0); 
        }
    }

    return 0;
}