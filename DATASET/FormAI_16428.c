//FormAI DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_TRIES 3

int main(void) {

    char password[MAX_LENGTH];
    char confirmPassword[MAX_LENGTH];
    int tries = 0;
    int isMatch = 0;

    printf("Welcome to the Password Manager 3000! I'll help you set up a secure password for your account.\n\n");

    while (!isMatch && tries < MAX_TRIES) {
        printf("Please enter your new password (max %d characters): ", MAX_LENGTH - 1);
        scanf("%s", password);

        printf("Please confirm your new password: ");
        scanf("%s", confirmPassword);

        if (strcmp(password, confirmPassword) == 0) {
            isMatch = 1;
        } else {
            tries++;
            printf("Passwords do not match! You have %d attempts left.\n\n", MAX_TRIES - tries);
        }
    }

    if (isMatch) {
        printf("\nPassword successfully set! Your password is: %s\n", password);
    } else {
        printf("\nYou have exceeded the maximum number of attempts. Please try again later.\n");
    }

    return EXIT_SUCCESS;
}