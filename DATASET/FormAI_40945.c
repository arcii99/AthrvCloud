//FormAI DATASET v1.0 Category: Password management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[30];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int user_count = 0;

// Function to add a user to the system
int add_user(char* username, char* password) {
    if (user_count == MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return -1;
    }
    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    user_count++;
    return 0;
}

// Function to check if a given username/password combination is valid
int authenticate(char* username, char* password) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 &&
            strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Add some users to the system
    add_user("Alice", "W0nderland");
    add_user("Bob", "Pa$$word123");
    add_user("Charlie", "S3cret");

    // Authenticate some users
    int auth1 = authenticate("Alice", "W0nderland");
    int auth2 = authenticate("Bob", "WrongPassword");
    int auth3 = authenticate("Charlie", "S3cret");

    // Print the authentication results
    printf("Alice: %s\n", auth1 ? "Authenticated" : "Not authenticated");
    printf("Bob: %s\n", auth2 ? "Authenticated" : "Not authenticated");
    printf("Charlie: %s\n", auth3 ? "Authenticated" : "Not authenticated");

    return 0;
}