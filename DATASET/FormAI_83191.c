//FormAI DATASET v1.0 Category: Password management ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USERS 100

// Define the user struct
typedef struct User {
    int id;
    char username[50];
    char password[50];
} User;

// Define the password manager struct
typedef struct PasswordManager {
    User users[MAX_USERS];
    int numOfUsers;
} PasswordManager;

// Initialize the password manager
void initialize(PasswordManager* manager) {
    manager->numOfUsers = 0;
}

// Add a new user to the password manager
void addUser(PasswordManager* manager, char* username, char* password) {
    User newUser;
    newUser.id = manager->numOfUsers + 1;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    manager->users[manager->numOfUsers] = newUser;
    manager->numOfUsers++;
}

// Update an existing user's password in the password manager
void updatePassword(PasswordManager* manager, char* username, char* newPassword) {
    for (int i = 0; i < manager->numOfUsers; i++) {
        if (strcmp(manager->users[i].username, username) == 0) {
            strcpy(manager->users[i].password, newPassword);
            printf("Password updated successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}

// Display all users in the password manager
void displayUsers(PasswordManager* manager) {
    if (manager->numOfUsers == 0) {
        printf("No users found.\n");
        return;
    }
    for (int i = 0; i < manager->numOfUsers; i++) {
        printf("ID: %d\n", manager->users[i].id);
        printf("Username: %s\n", manager->users[i].username);
        printf("Password: %s\n", manager->users[i].password);
        printf("---------------------\n");
    }
}

// Main function to test the password manager
int main() {
    PasswordManager manager;
    initialize(&manager);
    addUser(&manager, "alice", "p@ssw0rd");
    addUser(&manager, "bob", "qwerty");
    addUser(&manager, "charlie", "secret");
    displayUsers(&manager);
    updatePassword(&manager, "charlie", "newpassword");
    displayUsers(&manager);
    return 0;
}