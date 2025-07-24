//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_lowercase(char ch) {
    return ch >= 'a' && ch <= 'z';
}

bool is_uppercase(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool is_special(char ch) {
    return (ch >= '!' && ch <= '/') || (ch >= ':' && ch <= '@') ||
           (ch >= '[' && ch <= '`') || (ch >= '{' && ch <= '~');
}

// Function to check if the password is strong enough
bool is_password_strong(char* password) {
    int length = strlen(password);
    bool has_lowercase = false, has_uppercase = false, has_digit = false, has_special = false;
    for (int i = 0; i < length; i++) {
        if (is_lowercase(password[i])) {
            has_lowercase = true;
        } else if (is_uppercase(password[i])) {
            has_uppercase = true;
        } else if (is_digit(password[i])) {
            has_digit = true;
        } else if (is_special(password[i])) {
            has_special = true;
        }
    }
    return length >= 8 && has_lowercase && has_uppercase && has_digit && has_special;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    fgets(password, 100, stdin);

    // Remove the newline character from the password
    password[strcspn(password, "\n")] = 0;

    if (is_password_strong(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is not strong enough.\n"
               "It must be at least 8 characters long and contain at least one lowercase letter,\n"
               "one uppercase letter, one digit and one special character.\n");
    }

    return 0;
}