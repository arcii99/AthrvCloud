//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_BUF 1024 //maximum length of input string
#define MAX_ARGS 64 //maximum number of arguments

char *parse_input(char *input, char **args) {
    int i = 0;
    char *token = strtok(input, " ");
    while (token != NULL && i < MAX_ARGS-1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return args[0];
}

void execute_command(char **args) {
    pid_t pid; //process id variable
    int status; //status of child process
    pid = fork(); //create new child process
    if (pid == 0) { //child process
        if (execvp(args[0], args) == -1) {
            perror("Error executing command");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) { //error forking
        perror("Error forking child process");
    } else { //parent process
        do {
            waitpid(pid, &status, WUNTRACED); //wait for child process to finish
        } while (!WIFEXITED(status) && !WIFSIGNALED(status)); //loop until process exits or is interrupted
    }
}

int main() {
    char input[MAX_BUF]; //input string buffer
    char *args[MAX_ARGS]; //arguments array
    char *command; //command string
    while (1) { //continuous loop to read and execute commands
        printf("shell>> ");
        fgets(input, MAX_BUF, stdin); //read input from console
        input[strcspn(input, "\n")] = 0; //remove newline character from input
        command = parse_input(input, args); //parse input and return command string
        if (strcmp(command, "exit") == 0) { //exit command to break out of loop
            break;
        }
        execute_command(args); //execute command
    }
    return 0;
}