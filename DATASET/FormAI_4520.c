//FormAI DATASET v1.0 Category: System administration ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_NAME_LENGTH 20
#define MAX_PASS_LENGTH 16

// Struct to store user data
typedef struct {
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];
    int isAdmin;
} User;

// Array of user data
User users[MAX_USERS];

// Function to print user data
void printUser(User user) {
    printf("Username: %s\n", user.username);
    printf("Password: %s\n", user.password);
    printf("Is Admin: %s\n", user.isAdmin ? "Yes" : "No");
    printf("\n");
}

// Function to add a user to the array
void addUser(User newUser) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strlen(users[i].username) == 0) {
            users[i] = newUser;
            printf("User added successfully.\n\n");
            return;
        }
    }
    printf("Error: Maximum number of users reached.\n\n");
}

// Function to remove a user from the array
void removeUser(char *username) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].username[0] = '\0';
            users[i].password[0] = '\0';
            users[i].isAdmin = 0;
            printf("User removed successfully.\n\n");
            return;
        }
    }
    printf("Error: User not found.\n\n");
}

// Function to change a user's password
void changePassword(char *username, char *newPassword) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0) {
            strcpy(users[i].password, newPassword);
            printf("Password changed successfully.\n\n");
            return;
        }
    }
    printf("Error: User not found.\n\n");
}

int main() {
    // Initialize users
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        users[i].username[0] = '\0';
        users[i].password[0] = '\0';
        users[i].isAdmin = 0;
    }

    // Add sample users
    User adminUser = {"admin", "password", 1};
    addUser(adminUser);

    User regularUser = {"user", "password", 0};
    addUser(regularUser);

    // Print menu and handle user input
    int choice;
    char username[MAX_NAME_LENGTH];
    char password[MAX_PASS_LENGTH];
    char newPassword[MAX_PASS_LENGTH];
    while (1) {
        printf("1. View users\n");
        printf("2. Add user\n");
        printf("3. Remove user\n");
        printf("4. Change password\n");
        printf("5. Quit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < MAX_USERS; i++) {
                    if (strlen(users[i].username) > 0) {
                        printUser(users[i]);
                    }
                }
                break;
            case 2:
                printf("Enter username (max %d characters): ", MAX_NAME_LENGTH-1);
                scanf("%s", username);
                printf("Enter password (max %d characters): ", MAX_PASS_LENGTH-1);
                scanf("%s", password);
                printf("Is user an administrator? (1 = Yes, 0 = No): ");
                scanf("%d", &choice);
                User newUser = {username, password, choice};
                addUser(newUser);
                break;
            case 3:
                printf("Enter username: ");
                scanf("%s", username);
                removeUser(username);
                break;
            case 4:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter new password (max %d characters): ", MAX_PASS_LENGTH-1);
                scanf("%s", newPassword);
                changePassword(username, newPassword);
                break;
            case 5:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    }

    return 0;
}