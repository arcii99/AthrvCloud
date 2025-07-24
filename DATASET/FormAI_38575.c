//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100 // Maximum number of users that can be stored
#define MAX_PW_LENGTH 25 // Maximum length of password that can be stored
#define MAX_INPUT_LENGTH 100 // Maximum length of user input

// Struct to store user information
typedef struct User {
    char username[MAX_INPUT_LENGTH];
    char password[MAX_PW_LENGTH];
} User;

// Global variables
User users[MAX_USERS]; // Array to store user data
int numUsers = 0; // Number of users currently stored

// Function to validate password strength
int validatePassword(char *password) {
    int length = strlen(password);
    if (length < 8) { // Password must be at least 8 characters long
        return 0;
    }
    int hasUpper = 0; // Flag to check whether password has uppercase character
    int hasLower = 0; // Flag to check whether password has lowercase character
    int hasDigit = 0; // Flag to check whether password has digit
    int hasSpecial = 0; // Flag to check whether password has special character
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') { // Uppercase character
            hasUpper = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') { // Lowercase character
            hasLower = 1;
        } else if (password[i] >= '0' && password[i] <= '9') { // Digit
            hasDigit = 1;
        } else { // Special character
            hasSpecial = 1;
        }
    }
    if (hasUpper && hasLower && hasDigit && hasSpecial) { // Password meets all criteria
        return 1;
    } else { // Password does not meet all criteria
        return 0;
    }
}

// Function to add user
void addUser(char *username, char *password) {
    if (numUsers >= MAX_USERS) { // Cannot add any more users
        printf("Cannot add more users. Maximum number of users reached.\n");
        return;
    }
    if (strlen(username) > MAX_INPUT_LENGTH - 1) { // Input too long
        printf("Username input too long.\n");
        return;
    }
    if (strlen(password) > MAX_PW_LENGTH - 1) { // Input too long
        printf("Password input too long.\n");
        return;
    }
    // Validate password strength
    if (!validatePassword(password)) {
        printf("Password does not meet requirements:\n");
        printf("- At least 8 characters long\n");
        printf("- Contains at least one uppercase character\n");
        printf("- Contains at least one lowercase character\n");
        printf("- Contains at least one digit\n");
        printf("- Contains at least one special character\n");
        return;
    }
    // Add user to array
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    numUsers++;
    printf("User added successfully.\n");
}

// Function to display all users
void displayUsers() {
    printf("List of all users:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s\n", users[i].username);
    }
}

// Function to check if username exists
int userExists(char *username) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) { // Username found
            return 1;
        }
    }
    return 0; // Username not found
}

// Function to change password
void changePassword(char *username, char *oldPassword, char *newPassword) {
    // Find user
    int userIndex = -1;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) { // Username found
            userIndex = i;
            break;
        }
    }
    if (userIndex == -1) { // Username not found
        printf("Username not found.\n");
        return;
    }
    // Validate old password
    if (strcmp(users[userIndex].password, oldPassword) != 0) {
        printf("Invalid password.\n");
        return;
    }
    // Validate new password
    if (strlen(newPassword) > MAX_PW_LENGTH - 1) { // Input too long
        printf("Password input too long.\n");
        return;
    }
    if (!validatePassword(newPassword)) {
        printf("Password does not meet requirements:\n");
        printf("- At least 8 characters long\n");
        printf("- Contains at least one uppercase character\n");
        printf("- Contains at least one lowercase character\n");
        printf("- Contains at least one digit\n");
        printf("- Contains at least one special character\n");
        return;
    }
    // Update password
    strcpy(users[userIndex].password, newPassword);
    printf("Password updated successfully.\n");
}

int main() {
    // Example usage
    addUser("user1", "password1");
    addUser("user2", "Password2!");
    displayUsers();
    changePassword("user1", "password1", "newpassword1");
    changePassword("user2", "Password2!", "newpassword2");
    return 0;
}