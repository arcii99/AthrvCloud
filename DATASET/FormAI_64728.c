//FormAI DATASET v1.0 Category: Password management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 30
#define MAX_USERS 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} user_t;

user_t users[MAX_USERS];
int num_users = 0;

void add_user(char* username, char* password) {
    user_t new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    users[num_users] = new_user;
    num_users++;
}

int check_password(char* username, char* password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void update_password(char* username, char* new_password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].username, username) == 0) {
            strcpy(users[i].password, new_password);
            printf("Password updated successfully.\n");
            return;
        }
    }
    printf("User not found.\n");
}

int main() {
    // Example usage:
    add_user("alice", "password1");
    add_user("bob", "password2");
    add_user("charlie", "password3");

    // Check password:
    if (check_password("alice", "password1")) {
        printf("Alice's password is correct.\n");
    } else {
        printf("Alice's password is incorrect.\n");
    }

    // Update password:
    update_password("bob", "newpassword");
    if (check_password("bob", "newpassword")) {
        printf("Bob's new password is correct.\n");
    } else {
        printf("Bob's new password is incorrect.\n");
    }

    return 0;
}