//FormAI DATASET v1.0 Category: System administration ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a list of users and their passwords
    char users[10][20] = {"user1", "user2", "user3", "user4", "user5", "user6", "user7", "user8", "user9", "user10"};
    char passwords[10][20] = {"pass1", "pass2", "pass3", "pass4", "pass5", "pass6", "pass7", "pass8", "pass9", "pass10"};

    // Keep track of which user is currently logged in
    char current_user[20] = "";

    while (1) {
        char input[50];
        printf(">> ");
        fgets(input, 50, stdin);
        strtok(input, "\n");    // Remove trailing newline character

        // User has entered 'exit', exit the program
        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        // User has entered 'login', attempt to log them in
        else if (strcmp(input, "login") == 0) {
            // Prompt user for their username and password
            char username[20];
            char password[20];
            printf("Username: ");
            fgets(username, 20, stdin);
            strtok(username, "\n");    // Remove trailing newline character
            printf("Password: ");
            fgets(password, 20, stdin);
            strtok(password, "\n");    // Remove trailing newline character

            // Loop through list of users and check if username and password match
            int matched_user = -1;
            for (int i = 0; i < 10; i++) {
                if (strcmp(username, users[i]) == 0 && strcmp(password, passwords[i]) == 0) {
                    matched_user = i;
                    break;
                }
            }

            // If username and password match, login user
            if (matched_user != -1) {
                printf("Welcome, %s!\n", username);
                strcpy(current_user, username);
            }

            // If username and password do not match, display error message
            else {
                printf("Invalid username or password.\n");
            }
        }

        // User has entered 'logout'
        else if (strcmp(input, "logout") == 0) {
            if (strcmp(current_user, "") != 0) {
                printf("Goodbye, %s!\n", current_user);
                strcpy(current_user, "");
            }
            else {
                printf("You are not currently logged in.\n");
            }
        }

        // User has entered 'help'
        else if (strcmp(input, "help") == 0) {
            printf("Available commands: exit, login, logout, help\n");
        }

        // User has entered an invalid command
        else {
            printf("Invalid command. Type 'help' for a list of available commands.\n");
        }
    }

    return 0;
}