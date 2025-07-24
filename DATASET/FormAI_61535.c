//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define common words to avoid in passwords
char *COMMON_PASSWORDS[] = {
    "password",
    "123456",
    "12345678",
    "abc123",
    "qwerty",
    "monkey",
    "letmein",
    "dragon",
    "baseball",
    "football",
    "soccer",
    "mustang",
    "charlie",
    "michael",
    "hockey",
    "shadow",
    "master",
    "jennifer",
    "hunter",
    "asdfgh",
    "samantha",
    "qazwsx",
    "nicole",
    "killer",
    "superman",
    "batman",
    "trustno1",
    "iloveyou",
    "hello",
    "admin",
    "welcome",
    "monkey123"
};

// Define function to check if character is a digit
bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Define function to check if character is a letter
bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Define function to check if character is a special character
bool is_special(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' ||
            c == '^' || c == '&' || c == '*' || c == '(' || c == ')' ||
            c == '-' || c == '_' || c == '+' || c == '=' || c == '{' ||
            c == '}' || c == '[' || c == ']' || c == '|' || c == '\\' ||
            c == ':' || c == ';' || c == '"' || c == '\'' || c == '<' ||
            c == '>' || c == ',' || c == '.' || c == '?' || c == '/');
}

// Define function to check if string is a common password
bool is_common_password(char *password) {
    int num_common_passwords = sizeof(COMMON_PASSWORDS) / sizeof(COMMON_PASSWORDS[0]);
    for (int i = 0; i < num_common_passwords; i++) {
        if (strcmp(password, COMMON_PASSWORDS[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Define function to check password strength
void check_password_strength(char *password) {
    int length = strlen(password);
    int num_digits = 0;
    int num_letters = 0;
    int num_special = 0;
    int num_uppercase = 0;
    int num_lowercase = 0;
    bool has_common_password = is_common_password(password);

    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            num_digits++;
        } else if (is_letter(password[i])) {
            num_letters++;
            if (isupper(password[i])) {
                num_uppercase++;
            } else {
                num_lowercase++;
            }
        } else if (is_special(password[i])) {
            num_special++;
        }
    }

    // Check password strength and give suggestions for improvement
    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short. Must be at least %d characters.\n", MIN_PASSWORD_LENGTH);
    } else if (has_common_password) {
        printf("Password is too common and easy to guess.\n");
    } else if (num_digits == 0) {
        printf("Password should contain at least one digit.\n");
    } else if (num_letters == 0) {
        printf("Password should contain at least one letter.\n");
    } else if (num_special == 0) {
        printf("Password should contain at least one special character (!, @, #, etc.).\n");
    } else if (num_uppercase == 0) {
        printf("Password should contain at least one uppercase letter.\n");
    } else if (num_lowercase == 0) {
        printf("Password should contain at least one lowercase letter.\n");
    } else {
        printf("Password is strong and secure!\n");
    }
}

int main() {
    char password[100];

    printf("Enter a password: ");
    fgets(password, 100, stdin);

    // Remove newline character from password
    password[strcspn(password, "\n")] = '\0';

    check_password_strength(password);

    return 0;
}