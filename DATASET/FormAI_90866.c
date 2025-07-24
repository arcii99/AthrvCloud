//FormAI DATASET v1.0 Category: System administration ; Style: artistic
// Welcome to our system administration example program!
// In this program, we will be implementing a custom authentication system using SHA-1 hashing.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 25

typedef struct User {
    char username[MAX_PASSWORD_LENGTH];
    unsigned char hash[SHA_DIGEST_LENGTH];
} User;

User users[MAX_USERS];
int num_users = 0;

void add_user(char* username, char* password) {
    if (num_users == MAX_USERS) {
        printf("Max number of users reached! Cannot add user.\n");
        return;
    }
    
    User new_user;
    strncpy(new_user.username, username, MAX_PASSWORD_LENGTH);
    
    SHA1(password, strlen(password), new_user.hash);
    
    users[num_users++] = new_user;
}

int authenticate(char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(username, users[i].username) == 0) {
            unsigned char hash[SHA_DIGEST_LENGTH];
            SHA1(password, strlen(password), hash);
            
            if (memcmp(hash, users[i].hash, SHA_DIGEST_LENGTH) == 0) {
                return 1;
            }
        }
    }
    
    return 0;
}

int main() {
    printf("Welcome to our custom authentication system.\n");
    
    add_user("admin", "admin123");
    add_user("user1", "password1");
    add_user("user2", "password2");
    
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    while (1) {
        printf("Enter your username (or EXIT to quit): ");
        scanf("%s", username);
        if (strcmp(username, "EXIT") == 0) {
            break;
        }
        
        printf("Enter your password: ");
        scanf("%s", password);
        
        if (authenticate(username, password)) {
            printf("Authentication successful. Welcome, %s!\n", username);
        } else {
            printf("Authentication failed. Please try again.\n");
        }
    }
    
    return 0;
}