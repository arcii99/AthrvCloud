//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: imaginative
/* Welcome to the "Magical Shell" - a Unix-like shell program written in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_COMMAND_LENGTH 100

int main()
{
    char command[MAX_COMMAND_LENGTH];
    char* commands[MAX_COMMANDS];
    int i, num_commands;

    while (1) {
        printf("MagicalShell > ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        num_commands = 0;
        commands[num_commands] = strtok(command, " \n");

        while (commands[num_commands] != NULL && num_commands < MAX_COMMANDS-1) {
            num_commands += 1;
            commands[num_commands] = strtok(NULL, " \n");
        }
        commands[num_commands] = NULL;

        if (commands[0] == NULL) {
            continue;
        }

        if (strcmp(commands[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        if (strcmp(commands[0], "echo") == 0) {
            for (i = 1; i < num_commands; i++) {
                printf("%s ", commands[i]);
            }
            printf("\n");
            continue;
        }

        int pid = fork();

        if (pid < 0) {
            printf("Fork failed!\n");
            continue;
        }

        if (pid == 0) {
            /* child process */
            if (execvp(commands[0], commands) == -1) {
                printf("Command not found!\n");
            }
            exit(0);
        } else {
            /* parent process */
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}