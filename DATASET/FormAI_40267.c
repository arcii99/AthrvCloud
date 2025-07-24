//FormAI DATASET v1.0 Category: System administration ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

#define COMMAND_MAX_LENGTH 100

int main( int argc, char *argv[] )
{
    pid_t pid;
    char command[COMMAND_MAX_LENGTH];

    printf("Welcome to the System Administration Program!\n");

    while (1) {
        printf("Please enter the command you wish to execute: ");
        fgets(command, COMMAND_MAX_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character from input

        pid = fork();
        if (pid < 0) {
            perror("Failed to fork process");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // child process
            execlp(command, command, (char *) NULL);
            perror("Failed to execute command");
            exit(EXIT_FAILURE);
        } else { // parent process
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("Command exited with status %d\n", WEXITSTATUS(status));
            } else {
                printf("Command did not exit normally\n");
            }
        }
    }

    return 0;
}