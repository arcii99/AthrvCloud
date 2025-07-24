//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check password strength
int check_password_strength(char password[]) {
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, digit = 0, special_char = 0;

    // Check each character in the password
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
        }
        if (islower(password[i])) {
            lowercase++;
        }
        if (isdigit(password[i])) {
            digit++;
        }
        if (ispunct(password[i]) || isspace(password[i])) {
            special_char++;
        }
    }

    // Password requirements
    int password_strength = 0;
    if (length >= 8) {
        password_strength++;
    }
    if (uppercase >= 1) {
        password_strength++;
    }
    if (lowercase >= 1) {
        password_strength++;
    }
    if (digit >= 1) {
        password_strength++;
    }
    if (special_char >= 1) {
        password_strength++;
    }

    // Return password strength
    return password_strength;
}

int main(void) {
    char password[50];

    printf("Welcome to the Password Strength Checker!\n\n");
    printf("Please enter a password: ");
    fgets(password, 50, stdin);

    // Remove newline character
    password[strcspn(password, "\n")] = 0;

    // Check password strength
    int strength = check_password_strength(password);

    // Print password strength
    if (strength == 1) {
        printf("\nYour password strength is weak.\n");
    } else if (strength == 2) {
        printf("\nYour password strength is fair.\n");
    } else if (strength == 3) {
        printf("\nYour password strength is good.\n");
    } else if (strength == 4) {
        printf("\nYour password strength is strong.\n");
    } else if (strength == 5) {
        printf("\nYour password strength is very strong!\n");
    }

    return 0;
}