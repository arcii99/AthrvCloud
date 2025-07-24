//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

// Define struct to hold user data
typedef struct {
    char username[MAX_SIZE];
    char password[MAX_SIZE];
    int isAdmin; // 0 = regular user, 1 = admin
} User;

// Define struct to hold system data
typedef struct {
    User users[MAX_SIZE];
    int numOfUsers;
} System;

// Define function to add a new user to the system
void addUser(System *system, User newUser) {
    // Check if username is already in use
    for (int i = 0; i < system->numOfUsers; i++) {
        if (strcmp(newUser.username, system->users[i].username) == 0) {
            printf("Error: Username already in use.\n");
            return;
        }
    }
    
    // Add new user to system
    system->users[system->numOfUsers] = newUser;
    system->numOfUsers++;
    printf("New user added.\n");
}

// Define function to remove an existing user from the system
void removeUser(System *system, char *username) {
    int userIndex = -1;
    
    // Find user index
    for (int i = 0; i < system->numOfUsers; i++) {
        if (strcmp(username, system->users[i].username) == 0) {
            userIndex = i;
            break;
        }
    }
    
    // Check if user was found
    if (userIndex == -1) {
        printf("Error: User not found.\n");
        return;
    }
    
    // Remove user from system
    for(int i = userIndex; i < system->numOfUsers - 1; i++) {
        system->users[i] = system->users[i+1];
    }
    system->numOfUsers--;
    printf("User removed.\n");
}

int main() {
    // Initialize system
    System system = {.numOfUsers = 0};

    // Add an admin user
    User adminUser = {.username = "admin", .password = "password123", .isAdmin = 1};
    addUser(&system, adminUser);

    // Add a regular user
    User regularUser = {.username = "alice", .password = "password456", .isAdmin = 0};
    addUser(&system, regularUser);

    // Remove the regular user
    removeUser(&system, "alice");

    return 0;
}