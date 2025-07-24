//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the character is a digit
bool is_digit(char character) {
    return (character >= '0' && character <= '9');
}

// Function to check if the character is a lowercase alphabet
bool is_lowercase(char character) {
    return (character >= 'a' && character <= 'z');
}

// Function to check if the character is an uppercase alphabet
bool is_uppercase(char character) {
    return (character >= 'A' && character <= 'Z');
}

// Function to check if the character is a special character
bool is_special(char character) {
    return ((character >= '!' && character <= '/') ||
            (character >= ':' && character <= '@') ||
            (character >= '[' && character <= '`') ||
            (character >= '{' && character <= '~'));
}

// Function to calculate the password strength and return a score
int get_password_strength(char password[]) {
    int length = strlen(password);
    int score = 0;

    // Check for length of password
    if (length >= 8 && length <= 15) {
        score += 10;
    } else if (length > 15) {
        score += 20;
    }

    // Check for presence of uppercase, lowercase, digits and special characters
    bool has_uppercase = false;
    bool has_lowercase = false;
    bool has_digit = false;
    bool has_special = false;

    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            has_digit = true;
        } else if (is_lowercase(password[i])) {
            has_lowercase = true;
        } else if (is_uppercase(password[i])) {
            has_uppercase = true;
        } else if (is_special(password[i])) {
            has_special = true;
        }
    }

    if (has_uppercase) {
        score += 10;
    }

    if (has_lowercase) {
        score += 10;
    }

    if (has_digit) {
        score += 10;
    }

    if (has_special) {
        score += 20;
    }

    // Check for repeated characters
    bool has_repeat = false;
    for (int i = 0; i < length; i++) {
        int count = 0;
        for (int j = 0; j < length; j++) {
            if (i != j && password[i] == password[j]) {
                count++;
                if (count > 1) {
                    has_repeat = true;
                    break;
                }
            }
        }
        if (has_repeat) {
            break;
        }
    }

    if (!has_repeat) {
        score += 20;
    }

    return score;
}

int main() {
    char password[100];

    printf("Enter password: ");
    fgets(password, 100, stdin);

    // Remove newline character at the end of password
    password[strcspn(password, "\n")] = '\0';

    int strength = get_password_strength(password);

    // Determine strength of password based on score
    if (strength < 30) {
        printf("Weak password\n");
    } else if (strength < 60) {
        printf("Moderate password\n");
    } else if (strength < 90) {
        printf("Strong password\n");
    } else {
        printf("Very strong password\n");
    }

    return 0;
}