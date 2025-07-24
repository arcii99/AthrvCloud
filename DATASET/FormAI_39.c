//FormAI DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>

/* This program demonstrates string manipulation in a paranoid style. */

/* Define constants for maximum string lengths. */
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20

/* Define functions for string manipulation. */

/* Function to check if a string contains only alphanumeric characters. */
int isAlphanumeric(char *str) {
    int i = 0;
    while (str[i]) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
            return 0;
        }
        i++;
    }
    return 1;
}

/* Function to check if a string is a valid username. */
int isValidUsername(char *username) {
    /* Maximum length */
    if (strlen(username) > MAX_USERNAME_LENGTH) {
        return 0;
    }

    /* Alphanumeric */
    if (!isAlphanumeric(username)) {
        return 0;
    }

    return 1;
}

/* Function to check if a string is a valid password. */
int isValidPassword(char *password) {
    /* Maximum length */
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    /* Alphanumeric */
    if (!isAlphanumeric(password)) {
        return 0;
    }

    /* Contains at least one uppercase letter */
    int i = 0;
    while (password[i]) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
        i++;
    }

    return 0;
}


int main() {
    /* Define variables for input. */
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    /* Prompt the user for input. */
    printf("Enter your username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    /* Remove newline characters from input. */
    strtok(username, "\n");
    strtok(password, "\n");

    /* Validate input. */
    if (isValidUsername(username) && isValidPassword(password)) {
        printf("Welcome, %s!\n", username);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}