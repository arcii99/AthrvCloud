//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    char input[512]; // input buffer
    while (1) {
        printf("> "); // print shell prompt
        fgets(input, sizeof(input), stdin); // get input string
        input[strcspn(input, "\n")] = 0; // remove newline character
        if (strlen(input) == 0) continue; // ignore empty input
        char *argv[16]; // argument vector
        char *token = strtok(input, " "); // split input string into tokens
        int argc = 0; // argument count
        while (token != NULL) {
            argv[argc++] = token;
            token = strtok(NULL, " ");
        }
        argv[argc] = NULL; // add terminal NULL element to argument vector
        if (strcmp(argv[0], "exit") == 0) { // built-in exit command
            exit(0);
        } else if (strcmp(argv[0], "cd") == 0) { // built-in cd command
            if (argc <= 1) chdir(getenv("HOME")); // change directory to home if no argument provided
            else chdir(argv[1]); // change directory to specified path
        } else { // execute external command
            pid_t pid = fork();
            if (pid == 0) {
                execvp(argv[0], argv); // execute command
                perror("execvp failed"); // output error message if execvp fails
                exit(1);
            } else {
                int status;
                waitpid(pid, &status, 0); // wait for child process to finish
            }
        }
    }
    return 0;
}