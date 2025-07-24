//FormAI DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20 // maximum length of password
#define MAX_ATTEMPTS 3 // maximum attempts to enter correct password
#define PASSWORD "M1ndB3nd1ng" // the actual password, shh!

int main() {
    int attempts = 0; // variable to keep track of attempts

    printf("Welcome to Mind Bender Password Manager!\n\n");
    printf("Enter the master password to access the password manager.\n\n");

    do {
        char input[MAX_LENGTH];
        printf("Password: ");
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0) {
            printf("\nAccess granted. Here are your passwords:\n");
            // TODO: code to display list of passwords
            return 0; // exiting program as task is done
        } else {
            printf("ACCESS DENIED.\n");
            attempts++;

            if (attempts == MAX_ATTEMPTS) {
                printf("\nYou have exceeded the maximum attempts. The program will now exit.\n");
                return 0;
            } else {
                printf("You have %d attempts left.\n\n", MAX_ATTEMPTS - attempts);
            }
        }
    } while (attempts < MAX_ATTEMPTS);

    return 0;
}