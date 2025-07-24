//FormAI DATASET v1.0 Category: System administration ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pid;
    int status;

    printf("Welcome to the Medieval System Administration Program!\n\n");

    while(1) {
        printf("Enter the command to run: ");
        char command[100];
        fgets(command, sizeof(command), stdin);

        // Remove newline character from input
        command[strcspn(command, "\n")] = 0;

        pid = fork();

        if (pid < 0) {
            printf("Error: failed to create child process!\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            // Child process
            printf("Executing command: %s\n", command);
            system(command);
            exit(EXIT_SUCCESS);
        }
        else {
            // Parent process
            printf("Your command is being executed...\n");

            // Wait for child process to complete
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                // Child process exited normally
                printf("Command execution complete!\n");
            }
            else {
                // Child process exited abnormally
                printf("Error: command execution failed!\n");
            }
        }

        // Give the user a chance to run another command
        printf("\n");
    }

    return 0;
}