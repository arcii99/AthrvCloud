//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct user users[MAX_USERS];

void initialize_users() {
    for (int i = 0; i < MAX_USERS; i++) {
        users[i].username[0] = '\0';
        users[i].password[0] = '\0';
    }
}

void create_user(char* username, char* password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].username[0] == '\0') {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            printf("User created: %s\n", username);
            return;
        }
    }
    printf("Cannot create user: maximum number of users reached.\n");
}

void delete_user(char* username, char* password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            users[i].username[0] = '\0';
            users[i].password[0] = '\0';
            printf("User deleted: %s\n", username);
            return;
        }
    }
    printf("Cannot delete user: user not found or password incorrect.\n");
}

int main() {
    initialize_users();
    create_user("alice", "password123");
    create_user("bob", "mysecret");
    delete_user("alice", "password123");
    delete_user("eve", "hacker");
    return 0;
}