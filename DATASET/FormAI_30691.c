//FormAI DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_PASSWORDS_PER_USER 10
#define MAX_PASSWORD_LENGTH 20

char *passwords[MAX_USERS][MAX_PASSWORDS_PER_USER]; // a 2D array to store user passwords
char *users[MAX_USERS]; // an array to store user names
int num_users = 0; // keeps track of the number of registered users

void add_user(char *username) {
    users[num_users++] = strdup(username);
}

void add_password(char *username, char *password) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i], username) == 0) { // if the user already exists
            // find the first available slot to add the new password
            for (int j = 0; j < MAX_PASSWORDS_PER_USER; j++) {
                if (passwords[i][j] == NULL) {
                    passwords[i][j] = strdup(password);
                    return;
                }
            }
        }
    }
    // if the user does not exist, add them first and then add the password
    add_user(username);
    passwords[num_users-1][0] = strdup(password);
}

char *generate_password() {
    char *password = (char*)malloc((MAX_PASSWORD_LENGTH+1) * sizeof(char));
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        if (i == 0) {
            password[i] = toupper(rand() % 26 + 'a'); // first character is uppercase letter
        } else if (rand() % 2 == 0) {
            password[i] = rand() % 10 + '0'; // add a digit
        } else {
            password[i] = rand() % 26 + 'a'; // add a lowercase letter
        }
    }
    password[MAX_PASSWORD_LENGTH] = '\0'; // null-terminate the string
    return password;
}

void print_passwords(char *username) {
    printf("User %s has the following passwords:\n", username);
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i], username) == 0) { // if the user exists
            for (int j = 0; j < MAX_PASSWORDS_PER_USER; j++) {
                if (passwords[i][j] != NULL) {
                    printf("%s\n", passwords[i][j]); // print the password
                }
            }
            return;
        }
    }
    printf("User not found.\n"); // if the user does not exist
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // initialize the password array to NULL
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_PASSWORDS_PER_USER; j++) {
            passwords[i][j] = NULL;
        }
    }

    add_password("Alice", "password");
    add_password("Bob", "12345");
    add_password("Bob", "qwerty");
    add_password("Charlie", "abcdef");

    char *new_password = generate_password();
    add_password("Alice", new_password);

    print_passwords("Bob");

    free(new_password);
    return 0;
}