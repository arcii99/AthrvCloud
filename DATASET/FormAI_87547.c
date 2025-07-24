//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a given character is a digit
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Function to check if a given character is an uppercase alphabet
bool isUpper(char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

// Function to check if a given character is a lowercase alphabet
bool isLower(char ch) {
    return (ch >= 'a' && ch <= 'z');
}

// Function to check if a given character is a special symbol
bool isSymbol(char ch) {
    return (ch >= 32 && ch <= 47) || (ch >= 58 && ch <= 64) || (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126);
}

// Main function
int main() {
    char password[100];

    printf("Enter your password: ");
    fgets(password, 100, stdin);

    // Remove newline character from password
    password[strcspn(password, "\n")] = 0;

    int len = strlen(password);

    bool hasDigit = false;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasSymbol = false;

    // Check each character of password and update flags accordingly
    for (int i = 0; i < len; i++) {
        if (isDigit(password[i])) {
            hasDigit = true;
        } else if (isUpper(password[i])) {
            hasUpper = true;
        } else if (isLower(password[i])) {
            hasLower = true;
        } else if (isSymbol(password[i])) {
            hasSymbol = true;
        }
    }

    // Calculate password strength based on flags
    int strength = 0;
    if (len >= 8 && len <= 12) {
        strength++;
    }
    if (len > 12) {
        strength += 2;
    }
    if (hasDigit) {
        strength++;
    }
    if (hasUpper) {
        strength++;
    }
    if (hasLower) {
        strength++;
    }
    if (hasSymbol) {
        strength++;
    }

    // Print password strength
    printf("Your password strength is %d out of 6\n", strength);

    return 0;
}