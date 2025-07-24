//FormAI DATASET v1.0 Category: Error handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_ATTEMPTS 3

int main() {

    // Declare variables
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];
    int num_attempts = 0;
    int authenticated = 0;

    // Prompt user for username and password
    printf("Please enter your username: ");
    fgets(username, MAX_NAME_LENGTH, stdin);
    printf("Please enter your password: ");
    fgets(password, MAX_NAME_LENGTH, stdin);

    // Strip newline characters from inputs
    username[strcspn(username, "\n")] = '\0';
    password[strcspn(password, "\n")] = '\0';

    // Check if username and password match
    while (num_attempts < MAX_NUM_ATTEMPTS && !authenticated) {
        // Pretend to check username and password against a database
        if (strcmp(username, "admin") == 0 && strcmp(password, "correcthorsebatterystaple") == 0) {
            authenticated = 1;
            printf("Login successful!\n");
        } else {
            // Increment number of attempts and prompt user to try again
            num_attempts++;
            if (num_attempts < MAX_NUM_ATTEMPTS) {
                printf("Invalid login credentials. Please try again.\n");
                printf("Please enter your username: ");
                fgets(username, MAX_NAME_LENGTH, stdin);
                printf("Please enter your password: ");
                fgets(password, MAX_NAME_LENGTH, stdin);

                // Strip newline characters from inputs
                username[strcspn(username, "\n")] = '\0';
                password[strcspn(password, "\n")] = '\0';
            } else {
                printf("Too many login attempts. Please try again later.\n");
                exit(1); // Terminate program with error
            }
        }
    }

    return 0; // Exit program with success
}