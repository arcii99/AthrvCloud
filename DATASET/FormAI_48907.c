//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 3

int main(int argc, char *argv[]) {
    char password[32];
    int tries = 0;

    printf("Please enter the password: ");
    scanf("%s", password);

    while (tries < MAX_ATTEMPTS) {
        int incorrect = 0;
        char guess[32];

        printf("Enter your guess: ");
        scanf("%s", guess);

        if (strncmp(guess, password, strlen(password)) == 0) {
            printf("Access granted!\n");
            return 0;
        } else {
            printf("Incorrect password. Try again.\n");
        }

        tries++;
    }

    printf("Too many incorrect attempts. Access denied.\n");

    return 1;
}