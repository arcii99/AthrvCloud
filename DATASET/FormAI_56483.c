//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Alan Touring
// C Password Strength Checker by Chatbot Alan Turing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int minimum_length = 8;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;
    char special_chars[] = "!@#$%^&*()_+{}[];':\"\\|,.<>/?`~";

    printf("Welcome to the C Password Strength Checker by Chatbot Alan Turing!\n");
    printf("Please enter a password (maximum length of %d characters):\n", MAX_PASSWORD_LENGTH);
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0; // remove newline character from input

    if (strlen(password) < minimum_length) {
        printf("ERROR: Password must be at least %d characters long.\n", minimum_length);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        }
        if (islower(password[i])) {
            has_lowercase = 1;
        }
        if (isdigit(password[i])) {
            has_digit = 1;
        }
        if (strchr(special_chars, password[i]) != NULL) {
            has_special_char = 1;
        }
    }

    printf("Password strength: ");
    if (has_uppercase && has_lowercase && has_digit && has_special_char) {
        printf("STRONG\n");
    } else if ((has_uppercase || has_lowercase) && has_digit && has_special_char) {
        printf("MEDIUM\n");
    } else {
        printf("WEAK\n");
    }

    return 0;
}