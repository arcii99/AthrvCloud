//FormAI DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char command[100];
    int running = 1;

    while (running) {
        printf("Enter a command: ");
        fgets(command, 100, stdin);

        if (strncmp(command, "exit", 4) == 0) {
            running = 0;
            printf("Goodbye!\n");
        }
        else if (strncmp(command, "cwd", 3) == 0) {
            char *cwd = calloc(100, sizeof(char));
            getcwd(cwd, 100);
            printf("Current working directory: %s\n", cwd);
            free(cwd);
        }
        else if (strncmp(command, "ls", 2) == 0) {
            system("ls");
        }
        else if (strncmp(command, "pwd", 3) == 0) {
            system("pwd");
        }
        else {
            printf("Unknown command\n");
        }
    }

    return 0;
}