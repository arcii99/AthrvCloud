//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 1024

// Function to execute shell commands
void executeCommand(char *command) {
    char result[MAX_LENGTH];
    FILE *fp = popen(command, "r");

    if(fp == NULL) {
        printf("Failed to execute the command\n");
        exit(1);
    }

    while(fgets(result, MAX_LENGTH, fp) != NULL) {
        printf("%s\n", result);
    }

    pclose(fp);
}

int main() {
    char hostname[MAX_LENGTH];
    char command[MAX_LENGTH];

    // Get the hostname of the system
    if(gethostname(hostname, MAX_LENGTH) != 0) {
        printf("Failed to get the hostname\n");
        exit(1);
    }

    printf("Welcome to the system administration tool on %s\n", hostname);

    while(1) {
        printf("Enter a command:\n");
        fgets(command, MAX_LENGTH, stdin);

        if(strcmp(command, "exit\n") == 0) {
            printf("Bye!\n");
            break;
        }

        // Execute the user command
        executeCommand(command);
    }

    return 0;
}