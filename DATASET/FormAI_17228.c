//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3 // max number of attempts allowed
#define MAX_PASSWORD_LENGTH 10 // max password length

int main() {
    char password[MAX_PASSWORD_LENGTH + 1]; // actual password
    char attempt[MAX_PASSWORD_LENGTH + 1]; // user's attempt at password
    int attempts = 0; // number of attempts made so far

    strcpy(password, "1234"); // set the actual password

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter password: ");
        scanf("%s", attempt);

        if (strcmp(attempt, password) == 0) {
            printf("Access granted!\n");
            break; // exit while loop
        } else {
            printf("Access denied!\n");
            attempts++;
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Intrusion detected! Terminating program...\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}