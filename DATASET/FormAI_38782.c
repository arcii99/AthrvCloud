//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_ARGS 20
#define MAX_INPUT 512

// Function to parse user input and store arguments in args array
void parse_input(char *inputs, char **args, int *num_args)
{
    int i = 0;
    char *token;

    token = strtok(inputs, " \n\r\t");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \n\r\t");
    }
    *num_args = i;
    args[i] = NULL;
}

int main(int argc, char *argv[])
{
    char inputs[MAX_INPUT];
    char *args[MAX_ARGS];
    int num_args;
    pid_t pid;
    int status;

    while (1) {
        printf(">> ");
        fflush(stdout);

        fgets(inputs, MAX_INPUT, stdin);

        parse_input(inputs, args, &num_args);

        if (num_args == 0) {
            continue;
        }

        // Exit shell when user types "exit"
        if (strcmp(args[0], "exit") == 0) {
            printf("Exiting...\n");
            exit(0);
        }

        pid = fork();

        if (pid < 0) {
            perror("Fork Failed");
            exit(1);
        } 
        else if (pid == 0) {
            // Child process
            // Execute user command
            if (execvp(args[0], args) == -1) {
                perror("Execution Failed");
            }

            exit(0);
        } 
        else {
            // Parent process
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }

    }

    return 0;
}