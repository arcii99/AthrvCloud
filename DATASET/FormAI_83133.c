//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    printf("Welcome to HappyShell!\n");

    char input[MAX_LENGTH]; // create buffer to hold input
    char exitCommand[] = "exit\n"; // command to exit shell

    while (1) { // keep looping until user types "exit"
        printf("> "); // print prompt
        fgets(input, MAX_LENGTH, stdin); // get user input
        
        if (strcmp(input, exitCommand) == 0) { // check if user wants to exit shell
            printf("Goodbye! Have a happy day :)\n");
            break; // exit loop and program
        }
        
        // check for any other happy commands
        if (strcmp(input, "smile\n") == 0) {
            printf(":)\n");
            continue; // go back to top of loop
        }
        
        if (strcmp(input, "laugh\n") == 0) {
            printf("HAHAHAHAHAHAHA!\n");
            continue; // go back to top of loop
        }
        
        // if no happy command found, treat as regular shell command
        system(input); // execute shell command
    }

    return 0;
}