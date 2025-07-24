//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define BUFFER_SIZE 1024

int main() {
    char input[BUFFER_SIZE]; // buffer for reading user input
    while(1) {
        printf("$ "); // print shell prompt
        fgets(input, BUFFER_SIZE, stdin); // read user input
        input[strlen(input) - 1] = '\0'; // remove newline character
        char *args[MAX_ARGS];
        int i = 0;
        char *token;
        token = strtok(input, " ");
        while(token != NULL && i < MAX_ARGS) { // tokenization loop
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
        pid_t pid = fork(); // create child process
        if(pid < 0) { // fork error
            printf("Error: fork() failed\n");
        } else if(pid == 0) { // child process
            int status = execvp(args[0], args); // execute command
            if(status == -1) {
                printf("Error: command not found\n");
                exit(1);
            }
        } else { // parent process
            wait(NULL); // wait for child to finish
        }
    }
    return 0;
}