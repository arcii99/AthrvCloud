//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_COMMAND_LENGTH 50

// Define a User struct
typedef struct {
    char username[MAX_COMMAND_LENGTH];
    char password[MAX_COMMAND_LENGTH];
    int isAdmin;
} User;

// Initialize an array of users
User users[MAX_USERS];

// Keep track of the current number of users
int numUsers = 0;

// Define a function to add a user to the users array
void addUser(char* username, char* password, int isAdmin) {
    if (numUsers >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }
    
    // Create a new user struct and add it to the users array
    User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    newUser.isAdmin = isAdmin;
    users[numUsers++] = newUser;
    
    printf("User '%s' added successfully.\n", username);
}

// Define a function to remove a user from the users array
void removeUser(char* username) {
    int index = -1;
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: User not found.\n");
        return;
    }
    
    // Shift all the elements to the left starting from the index of the user to be removed
    for (int i = index; i < numUsers - 1; i++) {
        users[i] = users[i+1];
    }
    
    numUsers--;
    
    printf("User '%s' removed successfully.\n", username);
}

// Define a function to check the login credentials of a user
User* login(char* username, char* password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return &users[i];
        }
    }
    
    return NULL;
}

// Define the main function
int main() {
    addUser("admin", "password", 1);
    addUser("user", "1234", 0);
    
    User* loggedInUser = login("admin", "password");
    if (loggedInUser) {
        printf("Logged in as '%s'.\n", loggedInUser->username);
        if (loggedInUser->isAdmin) {
            printf("You have administrator access.\n");
        } else {
            printf("You do not have administrator access.\n");
        }
    } else {
        printf("Invalid login credentials.\n");
    }
    
    removeUser("admin");
    
    loggedInUser = login("admin", "password");
    if (loggedInUser) {
        printf("Logged in as '%s'.\n", loggedInUser->username);
        if (loggedInUser->isAdmin) {
            printf("You have administrator access.\n");
        } else {
            printf("You do not have administrator access.\n");
        }
    } else {
        printf("Invalid login credentials.\n");
    }
    
    return 0;
}