//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_symbol(char c) {
    return !is_alpha(c) && !is_digit(c);
}

int score_password(char* password) {
    int score = 0;
    int length = strlen(password);

    if (length < 8) {
        return 0; // Password is too short
    }

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (is_alpha(c)) {
            if (isupper(c)) {
                score += 2; // Uppercase letters are good
            } else {
                score += 1; // Lowercase letters are okay
            }
        } else if (is_digit(c)) {
            score += 2; // Digits are good
        } else if (is_symbol(c)) {
            score += 3; // Symbols are great
        }
    }

    return score;
}

bool is_strong_password(char* password) {
    int score = score_password(password);

    if (score < 10) {
        return false; // Password is too weak
    } else if (score < 20) {
        printf("This password is okay.\n"); // Password is okay
    } else if (score < 30) {
        printf("This password is strong.\n"); // Password is strong
    } else {
        printf("This password is paranoid!\n"); // Password is paranoid
    }

    return true;
}

int main() {
    char password[256];

    printf("Enter your password: ");
    fgets(password, 256, stdin); // Get input from user
    password[strcspn(password, "\n")] = 0; // Remove newline character

    if (!is_strong_password(password)) {
        printf("Your password is too weak. Please choose a stronger password.\n");
    }

    return 0;
}