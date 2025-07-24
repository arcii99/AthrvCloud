//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 100 // Maximum number of arguments user can specify
#define MAX_COMMANDS 100 // Maximum number of commands user can specify at a time

char* PROMPT = "Happy to serve you! Enter the command: ";

/*
 * This function reads the command entered by the user
 * @param command - stores the entered command
 */
void readCommand(char* command) {
    printf("%s", PROMPT);
    fgets(command, 1024, stdin); // read input from user
    command[strcspn(command, "\n")] = 0; // remove newline character
}

/*
 * This function tokenizes the entered command
 * @param command - the command entered by the user
 * @param args - an array that will contain the tokens
 * @return the number of tokens
 */
int tokenize(char* command, char** args) {
    int count = 0;
    char* token = strtok(command, " "); // split command into tokens

    while (token != NULL) {
        args[count] = token;
        count++;

        token = strtok(NULL, " ");
    }

    args[count] = NULL; // add NULL pointer at the end
    return count;
}

/*
 * This function executes the commands
 * @param command - the command entered by the user
 */
void execute(char* command) {
    char* args[MAX_ARGS];
    int numArgs = tokenize(command, args); // split command into tokens

    pid_t pid = fork();

    if (pid == -1) { // call to fork() failed
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // child process
        if (execvp(args[0], args) == -1) { // replace this process with new process
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else { // parent process
        int status;
        waitpid(pid, &status, 0); // wait for child process to terminate
    }
}

int main() {
    char command[1024];

    while (1) { // run indefinitely
        readCommand(command);
        execute(command);
    }

    return 0;
}