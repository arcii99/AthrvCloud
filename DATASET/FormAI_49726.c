//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

int main(void) {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length = 0;
    int num_lowercase = 0;
    int num_uppercase = 0;
    int num_numbers = 0;
    int num_special_chars = 0;
    int i;

    printf("Enter your password (max length %d): ", MAX_PASSWORD_LENGTH);
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    password[strcspn(password, "\n")] = 0;
    password_length = strlen(password);

    for (i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            num_lowercase++;
        } else if (isupper(password[i])) {
            num_uppercase++;
        } else if (isdigit(password[i])) {
            num_numbers++;
        } else if (!isalnum(password[i])) {
            num_special_chars++;
        }
    }

    printf("\nPassword strength analysis:\n");
    printf("  Password length: %d characters\n", password_length);
    printf("  Number of lowercase letters: %d\n", num_lowercase);
    printf("  Number of uppercase letters: %d\n", num_uppercase);
    printf("  Number of numbers: %d\n", num_numbers);
    printf("  Number of special characters: %d\n", num_special_chars);

    if (password_length >= 8 &&
        num_lowercase >= 1 &&
        num_uppercase >= 1 &&
        num_numbers >= 1 &&
        num_special_chars >= 1) {
        printf("\nPassword strength: Strong\n");
    } else {
        printf("\nPassword strength: Weak. Password must be at least 8 characters long and contain at least one of each of the following: lowercase letter, uppercase letter, number, special character.\n");
    }

    return EXIT_SUCCESS;
}