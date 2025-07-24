//FormAI DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char command[100];

    while (1) {
        printf("Enter a command: ");
        scanf("%[^\n]%*c", command);

        if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        }

        pid_t pid = fork();

        if (pid == -1) {
            printf("Error: Failed to fork!\n");
            exit(1);
        }

        if (pid == 0) {
            // Child process
            printf("Executing command...\n");
            system(command);
            printf("Command executed.\n");
            exit(0);
        } else {
            // Parent process
            int status;
            wait(&status);
            if (WIFEXITED(status)) {
                printf("Command returned with code %d.\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}