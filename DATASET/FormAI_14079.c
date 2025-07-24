//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 2048

int main()
{
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;
    int status;

    while (1) {
        printf("Enter a command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strlen(command) > 0 && command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0'; // Remove the newline character
        }

        if (strcmp(command, "exit") == 0) {
            break;
        }

        pid = fork();
        if (pid == 0) {
            // Child process: execute the command
            int result = system(command);
            _exit(result);
        } else if (pid < 0) {
            printf("Error: fork() failed\n");
        } else {
            // Parent process: wait for the child to finish
            pid_t terminated_pid = waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                // Child exited normally
                int exit_status = WEXITSTATUS(status);
                printf("Child process %d terminated with exit status %d\n", (int) terminated_pid, exit_status);
            } else if (WIFSIGNALED(status)) {
                // Child was terminated by a signal
                int signal_number = WTERMSIG(status);
                printf("Child process %d terminated by signal %d: %s\n", (int) terminated_pid, signal_number, strsignal(signal_number));
            } else {
                printf("Child process %d terminated abnormally\n", (int) terminated_pid);
            }
        }
    }

    return 0;
}