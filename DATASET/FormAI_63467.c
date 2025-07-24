//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 // max length of command
#define MAX_ARGS 10 // max number of arguments

int main(void) {
    char *args[MAX_ARGS];   // list of arguments
    char cmd[MAX_LINE];     // command string
    int should_run = 1;     // flag to determine when to exit program

    while (should_run) {
        printf("sh> ");
        fflush(stdout);     // prompt the user

        fgets(cmd, MAX_LINE, stdin);
        cmd[strcspn(cmd, "\n")] = 0; // remove new line character

        if (strcmp(cmd, "exit") == 0) {
            should_run = 0; // exit the shell if "exit"
            break;
        }

        pid_t pid = fork(); // create new process

        if (pid == -1) {
            printf("Error: Forking Failed!\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            char *token;
            int count = 0;

            token = strtok(cmd, " ");
            while (token != NULL) {
                args[count] = token;
                count++;
                token = strtok(NULL, " ");
            }
            args[count] = NULL; // set last element to NULL

            execvp(args[0], args); // execute command

            printf("Error: Unknown Command!\n");
            exit(1);
        } else {
            // Parent process
            wait(NULL); // wait for child process to finish
        }
    }

    return 0;
}