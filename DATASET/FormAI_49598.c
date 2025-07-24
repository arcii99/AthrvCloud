//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAX_ARGS 10
#define MAX_LINE_LENGTH 100

void parse_args(char* line, char** args_array) {
    char* token;
    int i = 0;
    token = strtok(line, " ");
    while(token != NULL && i < MAX_ARGS) {
        args_array[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args_array[i] = NULL;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char* args_array[MAX_ARGS];
    pid_t pid;
    int status;

    while(1) {
        printf("my_shell> ");
        fgets(line, MAX_LINE_LENGTH, stdin); // read line from user input
        line[strcspn(line, "\n")] = 0; // remove newline character from line

        if(strcmp(line, "exit") == 0) { // exit condition for shell
            printf("Exiting shell...\n");
            break;
        }

        parse_args(line, args_array); // parse arguments from user input

        pid = fork(); // create new process
        if(pid == -1) { // error with fork()
            perror("fork");
        } else if(pid == 0) { // child process
            execvp(args_array[0], args_array); // execute command with arguments
            perror("execvp");
            exit(EXIT_FAILURE);
        } else { // parent process
            if(waitpid(pid, &status, 0) == -1) { // wait for child process to finish
                perror("waitpid");
            }
        }
    }

    return 0;
}