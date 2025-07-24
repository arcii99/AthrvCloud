//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
    char password[1000];
    int length, hasUpperCase, hasLowerCase, hasDigit, hasSpecialChar, strengthScore = 0;

    printf("Enter your password: ");
    fgets(password, 1000, stdin);
    length = strlen(password) - 1;

    for (int i = 0; password[i] != '\0'; i++) {
        char currentChar = password[i];

        // Check for uppercase letters
        if (currentChar >= 'A' && currentChar <= 'Z') {
            hasUpperCase = 1;
            strengthScore += 20;
        }

        // Check for lowercase letters
        if (currentChar >= 'a' && currentChar <= 'z') {
            hasLowerCase = 1;
            strengthScore += 20;
        }

        // Check for digits
        if (currentChar >= '0' && currentChar <= '9') {
            hasDigit = 1;
            strengthScore += 20;
        }

        // Check for special characters
        if (currentChar == '!' || currentChar == '@' || currentChar == '#' || currentChar == '$' || currentChar == '%' || currentChar == '^' || currentChar == '&' || currentChar == '*' || currentChar == '(' || currentChar == ')' || currentChar == '-' || currentChar == '+' || currentChar == '=' || currentChar == '[' || currentChar == ']' || currentChar == '{' || currentChar == '}' || currentChar == ';' || currentChar == ':' || currentChar == '"' || currentChar == '\'' || currentChar == ',' || currentChar == '<' || currentChar == '.' || currentChar == '>' || currentChar == '/' || currentChar == '?' || currentChar == '\\' || currentChar == '|' || currentChar == '~') {
            hasSpecialChar = 1;
            strengthScore += 20;
        }
    }

    // Check length of password
    if (length >= 8 && length <= 12) {
        strengthScore += 20;
    } else if (length > 12 && length <= 16) {
        strengthScore += 40;
    } else if (length > 16) {
        strengthScore += 60;
    }

    // Display password strength
    if (hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) {
        printf("Your password is very strong! Strength score: %d\n", strengthScore);
    } else if ((hasUpperCase || hasLowerCase) && hasDigit && hasSpecialChar) {
        printf("Your password is strong. Strength score: %d\n", strengthScore);
    } else {
        printf("Your password is weak. Strength score: %d\n", strengthScore);
    }

    return 0;
}