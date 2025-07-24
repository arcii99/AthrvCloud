//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 100

int main() {

    char input[MAX_INPUT];
    printf("Welcome to Complex System Administration Program!\n");
    printf("Please enter a command or 'help' for a list of commands:\n");

    while(1) {

        // Get user input
        fgets(input, MAX_INPUT, stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for 'help' command
        if (strcmp(input, "help") == 0) {
            printf("List of commands:\n");
            printf("shutdown - shut down the system\n");
            printf("restart - restart the system\n");
            printf("users - display a list of all users on the system\n");
            printf("memory - display system memory information\n");
            printf("exit - exit the program\n");
        }

        // Check for 'shutdown' command
        else if (strcmp(input, "shutdown") == 0) {
            printf("Shutting down the system...\n");
            sleep(3); // Wait for 3 seconds for effect
            system("shutdown now"); // Execute the command
        }

        // Check for 'restart' command
        else if (strcmp(input, "restart") == 0) {
            printf("Restarting the system...\n");
            sleep(3); // Wait for 3 seconds for effect
            system("shutdown -r now"); // Execute the command
        }

        // Check for 'users' command
        else if (strcmp(input, "users") == 0) {
            printf("List of users on the system:\n");
            system("who"); // Execute the command
        }

        // Check for 'memory' command
        else if (strcmp(input, "memory") == 0) {
            printf("System memory information:\n");
            system("free -h"); // Execute the command
        }

        // Check for 'exit' command
        else if (strcmp(input, "exit") == 0) {
            printf("Exiting the program...\n");
            break;
        }

        // Invalid command
        else {
            printf("Invalid command, please try again or enter 'help' for a list of commands.\n");
        }

        printf("Please enter a command or 'help' for a list of commands:\n");
    }

    return 0;
}