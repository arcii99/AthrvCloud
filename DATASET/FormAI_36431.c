//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

void display_grateful_message() {
    printf("\n\t\t*** Welcome to the Grateful Shell! ***\n\n");
    printf("\tThis is a Unix-like shell program written in C language,\n");
    printf("\tcreated with love and gratitude by your friendly neighbourhood programmer.\n\n");
}

void display_prompt() {
    printf("grateful-shell > ");
}

int main() {
    display_grateful_message();

    char input[MAX_INPUT_LENGTH];
    char* command;

    while (1) {
        display_prompt();

        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strlen(input) - 1] = '\0';    // replace newline character with null terminator

        if (strcmp(input, "exit") == 0) {
            printf("\n\tThank you for using the Grateful Shell! Have a grateful day!\n\n");
            exit(0);
        }

        command = strtok(input, " ");
        if (command == NULL) continue;

        // add your code here to handle different commands
    }

    return 0;
}