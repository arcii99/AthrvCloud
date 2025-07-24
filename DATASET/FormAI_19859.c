//FormAI DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_LOGIN_TRIES 3

int main() {
    char password[MAX_PASSWORD_LENGTH];
    char userInput[MAX_PASSWORD_LENGTH];
    int loginTries = 0;

    //Ask user to set a new password
    printf("Welcome to the password manager program.\n");
    printf("Please set a new password (max length %d): ", MAX_PASSWORD_LENGTH - 1);
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';
    printf("New password set.\n");

    //Login loop with a maximum number of login tries set
    while (loginTries < MAX_LOGIN_TRIES) {
        printf("\nEnter your password to login (max length %d): ", MAX_PASSWORD_LENGTH - 1);
        fgets(userInput, MAX_PASSWORD_LENGTH, stdin);
        userInput[strcspn(userInput, "\n")] = '\0';

        //Compare password to user input and log user in if they match
        if (strcmp(password, userInput) == 0) {
            printf("Login successful. Welcome back!\n");
            break;
        }
        else {
            loginTries++;
            printf("Incorrect password. %d/%d attempts used.\n", loginTries, MAX_LOGIN_TRIES);
        }
    }

    //Terminate program if maximum login tries exceeded
    if (loginTries == MAX_LOGIN_TRIES)
        printf("Maximum login attempts exceeded. Program will now exit.\n");

    return 0;
}