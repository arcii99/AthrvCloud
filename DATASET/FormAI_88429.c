//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH+1];
    int password_length, i;

    srand(time(NULL));  // Seed random number generator with current time

    printf("Welcome to the Secure Password Generator!\n\n");

    do {
        printf("Please enter desired password length (1-%d): ", MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
    } while (password_length < 1 || password_length > MAX_PASSWORD_LENGTH);

    printf("\nGenerating password...\n\n");
    for (i = 0; i < password_length; i++) {
        int choice = rand() % 3;

        if (choice == 0) {  // Generate random uppercase letter
            password[i] = rand() % 26 + 'A';
        } else if (choice == 1) {  // Generate random lowercase letter
            password[i] = rand() % 26 + 'a';
        } else {  // Generate random digit
            password[i] = rand() % 10 + '0';
        }
    }

    password[password_length] = '\0';  // Add null terminator

    printf("Your secure password is: %s\n", password);

    return 0;
}