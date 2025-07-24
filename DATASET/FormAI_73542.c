//FormAI DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COMMAND_LENGTH 100

void welcome_message();

int main() {
    welcome_message();
    char command[COMMAND_LENGTH];
    while(1) {
        printf("\n> ");
        fgets(command, COMMAND_LENGTH, stdin);
        if (system(command)) {
            printf("Error executing command.\n");
        }
    }
    return 0;
}

void welcome_message() {
    printf("\n Welcome to the command shell. \n");
    printf("Enter any Linux command and press Enter. \n");
    printf("Type 'exit' to quit.\n");
}