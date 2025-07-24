//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: shocked
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/wait.h> 

#define MAX_CMD_LEN 1000
#define MAX_ARGS 100

char *parse_input(char *input, char **args) {

    int count = 0;
  
    char *token = strtok(input, " \t\n");
    while (token != NULL) {
        args[count] = token;
        count++;
        token = strtok(NULL, " \t\n");
    }
    args[count] = NULL;

    return args[0];
}

int execute_command(char **args) {

    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0) {
        printf("Error: Unable to fork child process!\n");
        exit(1);
    } else if (pid == 0) {
        // Child process starts here
        if (execvp(args[0], args) < 0) {
            printf("Error: Command not found!\n");
            exit(1);
        }
    } else {
        // Parent process waits for child to finish
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int main() {

    char input[MAX_CMD_LEN];
    char *args[MAX_ARGS];

    printf("Welcome to my Unix-like shell!\n");
    printf("Enter 'exit' to quit.\n");

    while (1) {
        printf("sh> ");

        if (fgets(input, MAX_CMD_LEN, stdin) == NULL) {
            printf("Error: Unable to read input!\n");
            exit(1);
        }

        if (strcmp(input, "exit\n") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        char *command = parse_input(input, args);
        if (strcmp(command, "cd") == 0) {
            if (chdir(args[1]) != 0) {
                printf("Error: Unable to change directory!\n");
            }
            continue;
        }

        execute_command(args);
    }

    return 0;
}