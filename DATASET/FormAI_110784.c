//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_NUMBER_OF_ARGUMENTS 10

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* command_arguments[MAX_NUMBER_OF_ARGUMENTS];

    while (1) {
        printf("$ ");

        fgets(command, MAX_COMMAND_LENGTH, stdin); // read command from user input
        command[strcspn(command, "\n")] = 0; // remove trailing newline character

        int i = 0;
        command_arguments[i] = strtok(command, " "); // the first argument is the command itself

        while (command_arguments[i] != NULL && i < MAX_NUMBER_OF_ARGUMENTS) {
            i++;
            command_arguments[i] = strtok(NULL, " "); // split the command string to arguments
        }

        pid_t pid = fork(); // fork the process to execute the command

        if (pid < 0) { // error
            perror("Error: fork failed\n");
        }
        else if (pid == 0) { // child process
            execvp(command_arguments[0], command_arguments); // execute the command with arguments
            perror("Error: exec failed\n");
            exit(1);
        }
        else { // parent process
            wait(NULL); // wait for the child process to finish
        }
    }

    return 0;
}