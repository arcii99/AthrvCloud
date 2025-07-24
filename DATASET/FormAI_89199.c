//FormAI DATASET v1.0 Category: Password management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAMES 10

// Function to check if a string contains only alphabets and numbers
int isAlphaNumeric(char *str) {
    int i;
    for(i=0; str[i]!='\0'; i++){
        if(!( (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0'&&str[i]<='9')))
            return 0;
    }
    return 1;
}

int main() {
    // Declaration of variables
    char usernames[MAX_USERNAMES][MAX_PASSWORD_LENGTH];
    char passwords[MAX_USERNAMES][MAX_PASSWORD_LENGTH];
    int numUsers = 0;
    char menuInput;
    char usernameInput[MAX_PASSWORD_LENGTH];
    char passwordInput[MAX_PASSWORD_LENGTH];

    // Printing the menu and getting the input
    while (1) {
        printf("\nWelcome to the Password Management System.\n");
        printf("Enter '1' to create a new account.\n");
        printf("Enter '2' to login to your existing account.\n");
        printf("Enter '3' to exit.\n");
        printf("Enter your choice: ");
        scanf(" %c", &menuInput);

        // Switch case for menu input
        switch (menuInput) {
            case '1':
                // Creating a new account
                printf("\nUsername: ");
                scanf("%s", usernameInput);

                // Validation checks on username
                if (numUsers == MAX_USERNAMES) {
                    printf("Error: Maximum number of users created.");
                    break;
                }
                if (!isAlphaNumeric(usernameInput)) {
                    printf("Error: Username can only contain alphabets and numbers.");
                    break;
                }

                // Checking if username is already taken
                int i;
                for (i = 0; i < numUsers; i++) {
                    if (strcmp(usernameInput, usernames[i]) == 0) {
                        printf("Error: Username is already taken.");
                        break;
                    }
                }

                // Getting password from user and adding information to arrays
                printf("Password: ");
                scanf("%s", passwordInput);
                strcpy(usernames[numUsers], usernameInput);
                strcpy(passwords[numUsers], passwordInput);
                numUsers++;
                printf("Account created successfully.");
                break;

            case '2':
                // Logging into an existing account
                printf("\nUsername: ");
                scanf("%s", usernameInput);
                printf("Password: ");
                scanf("%s", passwordInput);

                // Checking if username exists and password matches
                int j;
                for (j = 0; j < numUsers; j++) {
                    if (strcmp(usernameInput, usernames[j]) == 0 && strcmp(passwordInput, passwords[j]) == 0) {
                        printf("Login successful.");
                        break;
                    }
                }
                if (j == numUsers) {
                    printf("Error: Invalid username or password.");
                }
                break;

            case '3':
                // Exiting the program
                printf("Exiting the program...");
                exit(0);

            default:
                printf("Error: Invalid input. Please try again.");
                break;
        }
    }
    return 0;
}