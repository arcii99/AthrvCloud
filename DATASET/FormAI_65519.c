//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void  handle_sigint(int sig);
void execute_cmd(char **args);

int main() {

    char input[MAX_INPUT];
    char *stdin_args[MAX_ARGS];
    int stdin_argc;
    struct sigaction sa;

    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Error: cannot handle SIGINT");
        exit(EXIT_FAILURE);
    }

    while(1) {
        // Print shell prompt
        printf("☢️ ");

        // Read user input
        fgets(input, MAX_INPUT, stdin);

        // Turn input string into array of arguments
        stdin_argc = 0;
        for (char *token = strtok(input, " \n"); token != NULL; token = strtok(NULL, " \n")) {
            stdin_args[stdin_argc++] = token;
        }
        stdin_args[stdin_argc] = NULL;

        // Execute command
        execute_cmd(stdin_args);
    }

    return 0;
}

void execute_cmd(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return;  // Ignore empty input
    }

    pid = fork();

    if (pid < 0) {
        perror("Error: Fork Failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            printf("Command not found: %s\n", args[0]);
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

void handle_sigint(int sig) {
    printf("\nType 'exit' to quit the shell\n");
}