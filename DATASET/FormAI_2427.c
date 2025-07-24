//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {

    char command[50];
    printf("Greetings user, you have entered the Shell of the Surreal!\n");
    printf("What would you like to do?\n");

    while (1) {
        printf("\n-> ");
        fgets(command, 50, stdin);

        // Replacing the newline character at the end of the command with a null character
        char *pos;
        if ((pos = strchr(command, '\n')) != NULL)
            *pos = '\0';

        if (strcmp(command, "exit") == 0) {
            printf("\nThank you for exploring the Surreal Shell. We hope to see you soon!\n");
            break;
        }

        pid_t pid = fork();

        if (pid < 0) {
            printf("\nSomething went wrong! The dream turned into a nightmare. Please come back again.\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            system(command);
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }
    }
    return 0;
}