//FormAI DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "password123" // define password
#define MAX_ATTEMPTS 3 // define max login attempts
#define MAX_USERS 10 // define max users

// define user struct
typedef struct {
    char username[20];
    char password[20];
} User;

User users[MAX_USERS]; // declare user array
int numUsers = 0; // initialize number of users to 0

// function to add a user
void addUser(char *username, char *password) {
    if(numUsers >= MAX_USERS) { // check if user array is full
        printf("User database is full!\n");
        return;
    }
    User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    users[numUsers] = newUser;
    numUsers++;
}

// function to remove user
void removeUser(char *username) {
    int found = 0;
    for(int i = 0; i < numUsers; i++) {
        if(strcmp(users[i].username, username) == 0) { // check if user exists
            found = 1;
            for(int j = i; j < numUsers-1; j++) { // shift remaining elements to fill the gap
                users[j] = users[j+1];
            }
            numUsers--;
            printf("User \"%s\" successfully removed.\n", username);
            break;
        }
    }
    if(!found) printf("User \"%s\" not found.\n", username);
}

// function to login
int loginUser() {
    int attemptsLeft = MAX_ATTEMPTS;
    char username[20];
    char password[20];
    while(attemptsLeft > 0) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);
        for(int i = 0; i < numUsers; i++) { // loop through users
            if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) { // check if username and password match
                return 1;
            }
        }
        attemptsLeft--;
        printf("Login failed. %d attempts left.\n", attemptsLeft);
    }
    printf("Login failed. No attempts left.\n");
    return 0;
}

// function to change password
void changePassword(char *username, char *newPassword) {
    int found = 0;
    for(int i = 0; i < numUsers; i++) {
        if(strcmp(users[i].username, username) == 0) { // check if user exists
            found = 1;
            strcpy(users[i].password, newPassword);
            printf("Password for user \"%s\" successfully changed.\n", username);
            break;
        }
    }
    if(!found) printf("User \"%s\" not found.\n", username);
}

int main() {
    // create some initial users
    addUser("user1", "password1");
    addUser("user2", "password2");
    addUser("user3", "password3");

    // prompt for login
    printf("Log in to continue.\n");
    if(!loginUser()) {
        printf("Program terminated.\n");
        return 0;
    }

    // menu loop
    int choice = 0;
    while(choice != 4) {
        printf("\n1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Change password\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                char username[20];
                char password[20];
                printf("Enter new username: ");
                scanf("%s", username);
                printf("Enter new password: ");
                scanf("%s", password);
                addUser(username, password);
                break;
            }
            case 2: {
                char username[20];
                printf("Enter username to remove: ");
                scanf("%s", username);
                removeUser(username);
                break;
            }
            case 3: {
                char username[20];
                char newPassword[20];
                printf("Enter username to change password: ");
                scanf("%s", username);
                printf("Enter new password: ");
                scanf("%s", newPassword);
                changePassword(username, newPassword);
                break;
            }
            case 4: {
                printf("Program terminated.\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}