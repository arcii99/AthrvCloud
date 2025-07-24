//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

int main()
{
    int attempts = 0;
    char password[MAX_PASSWORD_LENGTH];
    char expected_password[MAX_PASSWORD_LENGTH] = "password123";

    printf("Please enter your password: ");
    scanf("%s", password);

    while (strncmp(password, expected_password, MAX_PASSWORD_LENGTH) != 0) {
        printf("Sorry, that's not the correct password. Please try again: ");
        scanf("%s", password);
        attempts++;

        if (attempts > 5) {
            printf("Too many attempts. Goodbye.");
            exit(1);
        }
    }

    printf("Password correct! Welcome to the program.\n");
    return 0;
}