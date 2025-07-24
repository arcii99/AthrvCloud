//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 10
#define MAX_COMMAND_LENGTH 100

int main(int argc, char *argv[]) {
    char command[MAX_COMMAND_LENGTH];
    char *command_args[MAX_ARGS];
    char *commands[MAX_COMMANDS];
    int num_commands = 0;

    while(1) {
        printf("MyShell> ");

        // Take command input from the user
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove the trailing newline character
        command[strcspn(command, "\n")] = 0;

        // If the user enters "exit", exit the shell
        if(strcmp(command, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        // Split the command into individual tokens
        char *token = strtok(command, " ");
        int i = 0;
        while(token != NULL) {
            command_args[i++] = token;
            token = strtok(NULL, " ");
        }
        command_args[i] = NULL;

        // If the user enters multiple commands separated by ";"
        token = strtok(command, ";");
        while(token != NULL) {
            commands[num_commands++] = token;
            if(num_commands >= MAX_COMMANDS) {
                printf("Too many commands entered!\n");
                break;
            }
            token = strtok(NULL, ";");
        }

        // Run each command entered
        int command_index;
        for(command_index = 0; command_index < num_commands; command_index++) {
            int num_args = 0;
            char *args[MAX_ARGS];

            // Split each command into its individual arguments
            token = strtok(commands[command_index], " ");
            while(token != NULL) {
                args[num_args++] = token;
                token = strtok(NULL, " ");
            }
            args[num_args] = NULL;

            // Fork a new process to run the command
            pid_t pid = fork();

            // If the pid is negative, there was an error forking
            if(pid < 0) {
                printf("Error: Fork failed!\n");
                exit(1);
            }
            // If the pid is 0, this is the child process and we need to execute the command
            else if(pid == 0) {
                // Run the command with the specified arguments
                if(execvp(args[0], args) < 0) {
                    printf("Error: Unable to execute \"%s\" command!\n", args[0]);
                    exit(1);
                }
            }
            // If the pid is greater than 0, this is the parent process and we need to wait for the child to complete
            else {
                wait(NULL);
            }
        }

        // Reset for the next set of commands
        num_commands = 0;
    }

    return 0;
}