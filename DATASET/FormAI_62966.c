//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MINIMUM_PASSWORD_LENGTH 8
#define MAXIMUM_PASSWORD_LENGTH 20

// Function to check if a given password is strong enough
int isPasswordStrong(char *password) {
    int lowercaseCount = 0;
    int uppercaseCount = 0;
    int digitCount = 0;
    int symbolCount = 0;

    int passwordLength = strlen(password);

    // Check if password meets minimum length requirement
    if(passwordLength < MINIMUM_PASSWORD_LENGTH) {
        return 0;
    }

    // Check if password exceeds maximum length requirement
    if(passwordLength > MAXIMUM_PASSWORD_LENGTH) {
        return 0;
    }

    for(int i = 0; i < passwordLength; i++) {
        char ch = password[i];

        // Check for uppercase letters
        if(isupper(ch)) {
            uppercaseCount++;
        }

        // Check for lowercase letters
        if(islower(ch)) {
            lowercaseCount++;
        }

        // Check for digits
        if(isdigit(ch)) {
            digitCount++;
        }

        // Check for symbols
        if(!isalnum(ch)) {
            symbolCount++;
        }
    }

    // Check if password contains at least one lowercase letter, uppercase letter, digit, and symbol
    if(lowercaseCount == 0 || uppercaseCount == 0 || digitCount == 0 || symbolCount == 0) {
        return 0;
    }

    // Password meets all requirements
    return 1;
}

int main() {
    char password[MAXIMUM_PASSWORD_LENGTH + 1];

    printf("Enter password: ");

    // Read user input
    fgets(password, sizeof(password), stdin);

    // Remove trailing newline character
    password[strcspn(password, "\n")] = '\0';

    // Check if password is strong enough
    if(isPasswordStrong(password)) {
        printf("Your password is STRONG!\n");
    } else {
        printf("Your password is not strong enough.\n");
    }

    return 0;
}