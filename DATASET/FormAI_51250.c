//FormAI DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

// Structure to store passwords
typedef struct {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

// Function to strip newline character from input
void stripNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    int numPasswords = 0;
    PasswordEntry passwords[MAX_PASSWORDS];

    // Welcome message
    printf("Welcome to Password Manager.\n\n");

    // Main loop
    while (1) {
        printf("Please choose an option:\n");
        printf("  1. Add a password\n");
        printf("  2. View passwords\n");
        printf("  3. Quit\n");

        // Get user input
        char input[10];
        fgets(input, sizeof(input), stdin);

        // Strip newline from input
        stripNewline(input);

        // Process user input
        if (strcmp(input, "1") == 0) {
            // Add password
            printf("\n");
            printf("Please enter the service name: ");
            fgets(passwords[numPasswords].service, MAX_PASSWORD_LENGTH, stdin);
            stripNewline(passwords[numPasswords].service);

            printf("Please enter the username: ");
            fgets(passwords[numPasswords].username, MAX_PASSWORD_LENGTH, stdin);
            stripNewline(passwords[numPasswords].username);

            printf("Please enter the password: ");
            fgets(passwords[numPasswords].password, MAX_PASSWORD_LENGTH, stdin);
            stripNewline(passwords[numPasswords].password);

            numPasswords++;
            printf("Password added!\n\n");
        } else if (strcmp(input, "2") == 0) {
            // View passwords
            printf("\n");
            if (numPasswords == 0) {
                printf("No passwords stored.\n\n");
            } else {
                printf("Service Name\tUsername\tPassword\n");
                printf("------------\t--------\t--------\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("%s\t%s\t%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
                }
                printf("\n");
            }
        } else if (strcmp(input, "3") == 0) {
            // Quit
            printf("\nGoodbye!\n");
            break;
        } else {
            // Invalid input
            printf("\nInvalid input. Please try again.\n\n");
        }
    }

    return 0;
}