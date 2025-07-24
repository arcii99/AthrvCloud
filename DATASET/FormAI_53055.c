//FormAI DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_CHARS 50

struct Password {
    char username[MAX_CHARS];
    char password[MAX_CHARS];
    int isDeleted;
};

struct Password passwords[MAX_ROWS];
int rowsInUse = 0;

// Function to create a new password
void createPassword() {
    if (rowsInUse < MAX_ROWS) {
        struct Password newPassword;
        printf("Enter username: ");
        fgets(newPassword.username, MAX_CHARS, stdin);
        printf("Enter password: ");
        fgets(newPassword.password, MAX_CHARS, stdin);
        newPassword.isDeleted = 0;
        passwords[rowsInUse++] = newPassword;
        printf("New password created!\n");
    } else {
        printf("Maximum number of passwords reached!\n");
    }
}

// Function to display all saved passwords
void displayPasswords() {
    printf("Stored Passwords:\n");
    for (int i = 0; i < rowsInUse; i++) {
        if (!passwords[i].isDeleted) {
            printf("    %d. Username: %s    Password: %s\n", i+1, passwords[i].username, passwords[i].password);
        }
    }
}

// Function to search for a password by username
int searchByUsername(char* searchUsername) {
    for (int i = 0; i < rowsInUse; i++) {
        if (!passwords[i].isDeleted && strcmp(passwords[i].username, searchUsername) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to update an existing password
void updatePassword() {
    char searchUsername[MAX_CHARS];
    printf("Enter username of password to update: ");
    fgets(searchUsername, MAX_CHARS, stdin);
    int index = searchByUsername(searchUsername);
    if (index != -1) {
        printf("Enter new username (press enter to keep current username): ");
        fgets(passwords[index].username, MAX_CHARS, stdin);
        printf("Enter new password (press enter to keep current password): ");
        fgets(passwords[index].password, MAX_CHARS, stdin);
        printf("Password updated!\n");
    } else {
        printf("Password not found!\n");
    }
}

// Function to delete an existing password
void deletePassword() {
    char searchUsername[MAX_CHARS];
    printf("Enter username of password to delete: ");
    fgets(searchUsername, MAX_CHARS, stdin);
    int index = searchByUsername(searchUsername);
    if (index != -1) {
        passwords[index].isDeleted = 1;
        printf("Password deleted!\n");
    } else {
        printf("Password not found!\n");
    }
}

int main() {
    char choice[MAX_CHARS];
    while (1) {
        printf("\nMenu:\n1. Create Password\n2. Display Passwords\n3. Update Password\n4. Delete Password\n5. Exit\nEnter choice: ");
        fgets(choice, MAX_CHARS, stdin);
        switch (atoi(choice)) {
            case 1:
                createPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                updatePassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}