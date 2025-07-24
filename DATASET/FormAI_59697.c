//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5

// A struct to hold user information
struct user {
    char username[20];
    char password[20];
};

// An array to hold all the user information
struct user users[MAX_USERS];

// Helper function to clear input buffer
void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to check if a username already exists in the system
int userExists(char *username) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(username, users[i].username) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to register a new user
void registerUser() {
    printf("Please enter a username: ");
    char username[20];
    scanf("%s", username);
    clearInputBuffer();

    // Check if user already exists
    if (userExists(username)) {
        printf("Username already exists. Please choose a different one.\n");
        return;
    }

    printf("Please enter a password: ");
    char password[20];
    scanf("%s", password);
    clearInputBuffer();

    // Add user to database
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].username[0] == '\0') {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            printf("User successfully registered!\n");
            return;
        }
    }

    printf("Database full. Cannot register new user.\n");
}

// Function to log in a user
void loginUser() {
    printf("Please enter your username: ");
    char username[20];
    scanf("%s", username);
    clearInputBuffer();

    // Find user in database
    struct user *u = NULL;
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(username, users[i].username) == 0) {
            u = &users[i];
            break;
        }
    }

    if (u == NULL) {
        printf("User not found.\n");
        return;
    }

    printf("Please enter your password: ");
    char password[20];
    scanf("%s", password);
    clearInputBuffer();

    if (strcmp(password, u->password) != 0) {
        printf("Incorrect password.\n");
        return;
    }

    printf("Welcome back, %s!\n", u->username);
}

// Function to change a user's password
void changePassword() {
    printf("Please enter your username: ");
    char username[20];
    scanf("%s", username);
    clearInputBuffer();

    // Find user in database
    struct user *u = NULL;
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(username, users[i].username) == 0) {
            u = &users[i];
            break;
        }
    }

    if (u == NULL) {
        printf("User not found.\n");
        return;
    }

    printf("Please enter your old password: ");
    char oldPassword[20];
    scanf("%s", oldPassword);
    clearInputBuffer();

    if (strcmp(oldPassword, u->password) != 0) {
        printf("Incorrect password.\n");
        return;
    }

    printf("Please enter a new password: ");
    char newPassword[20];
    scanf("%s", newPassword);
    clearInputBuffer();

    strcpy(u->password, newPassword);
    printf("Password successfully changed for %s.\n", u->username);
}

// Main function
int main() {
    // Initialize user database
    for (int i = 0; i < MAX_USERS; i++) {
        users[i].username[0] = '\0';
        users[i].password[0] = '\0';
    }

    // Main menu loop
    while (1) {
        printf("\nWelcome to the password management system!\n");
        printf("Please choose an option:\n");
        printf("1. Register a new user\n");
        printf("2. Log in as an existing user\n");
        printf("3. Change your password\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}