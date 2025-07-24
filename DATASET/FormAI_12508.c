//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, i;
    int upper_case = 0, lower_case = 0, digit = 0, special_char = 0;

    printf("Enter your password (max length %d): ", MAX_PASSWORD_LENGTH);
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character from fgets
    password[strcspn(password, "\n")] = 0;

    length = strlen(password);

    // Check password length
    if (length < 8) {
        printf("Your password is too short. Please enter a password with at least 8 characters.\n");
        return 0;
    }

    // Check if password contains uppercase letters, lowercase letters, digits, and special characters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper_case = 1;
        }
        else if (islower(password[i])) {
            lower_case = 1;
        }
        else if (isdigit(password[i])) {
            digit = 1;
        }
        else {
            special_char = 1;
        }
    }

    // Print results based on password strength
    if (upper_case && lower_case && digit && special_char) {
        printf("Congratulations, your password is very strong.\n");
    }
    else if ((upper_case && lower_case && digit) || (upper_case && lower_case && special_char) ||
             (upper_case && digit && special_char) || (lower_case && digit && special_char)) {
        printf("Your password is strong, but it could be better. Please consider including a special character.\n");
    }
    else {
        printf("Your password is weak. Please ensure that it includes both uppercase and lowercase letters, a digit, and a special character.\n");
    }

    return 0;
}