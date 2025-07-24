//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMANDS 50
#define MAX_COMMAND_LENGTH 100

void printPrompt() {
    printf("  _____ __  __ _____   ____  _____ _____ \n");
    printf(" / ____|  \\/  |  __ \\ / __ \\|  __ \\_   _| \n");
    printf("| (___ | \\  / | |__) | |  | | |__) || | \n");
    printf(" \\___ \\| |\\/| |  ___/| |  | |  _  / | | \n");
    printf(" ____) | |  | | |    | |__| | | \\ \\ |_| \n");
    printf("|_____/|_|  |_|_|     \\____/|_|  \\_\\_____| \n");
    printf("> ");
}

int main() {
    char input[1000];

    while (1) {
        printPrompt();
        fgets(input, sizeof(input), stdin);

        char* commands[MAX_COMMANDS];
        int count = 0;

        // Parse the input command into separate commands
        char* token = strtok(input, " \n");

        while (token != NULL) {
            commands[count] = token;
            count++;
            token = strtok(NULL, " \n");
        }

        commands[count] = NULL;

        if (count == 0) {
            continue;
        }

        // Special command to exit the shell
        if (strcmp(commands[0], "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        int pid = fork();

        if (pid == 0) {
            // Child process
            execvp(commands[0], commands);

            printf("Error executing command!\n");
            exit(1);
        }
        else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}