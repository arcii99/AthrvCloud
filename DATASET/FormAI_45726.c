//FormAI DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 12
#define MAX_USERNAME_LENGTH 12

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User* authenticate() {
    struct User* user = (struct User*) calloc(1, sizeof(struct User)); // allocate memory
    char tempName[MAX_USERNAME_LENGTH];
    char tempPswd[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    fgets(tempName, MAX_USERNAME_LENGTH, stdin); // get user input
    tempName[strcspn(tempName, "\n")] = 0; // remove newline character from input
    printf("Enter your password: ");
    fgets(tempPswd, MAX_PASSWORD_LENGTH, stdin);
    tempPswd[strcspn(tempPswd, "\n")] = 0;
    if (strcmp(tempName, "admin") == 0 && strcmp(tempPswd, "password") == 0) { // perform authentication
        strncpy(user->username, tempName, MAX_USERNAME_LENGTH); // add username and password to struct
        strncpy(user->password, tempPswd, MAX_PASSWORD_LENGTH);
        return user;
    } else {
        free(user); // free memory if authentication is unsuccessful
        return NULL;
    }
}

int main() {
    struct User* user = authenticate();
    if (user == NULL) {
        printf("Authentication failed\n");
    } else {
        printf("Welcome %s!\n", user->username);
    }
    free(user); // free memory after use
    return 0;
}