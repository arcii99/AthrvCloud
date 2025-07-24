//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if password contains uppercase letter
bool contains_uppercase(char *password) {
    int len = strlen(password);
    int i;

    for (i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return true;
        }
    }

    return false;
}

// Function to check if password contains lowercase letter
bool contains_lowercase(char *password) {
    int len = strlen(password);
    int i;

    for (i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return true;
        }
    }

    return false;
}

// Function to check if password contains digit
bool contains_digit(char *password) {
    int len = strlen(password);
    int i;

    for (i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return true;
        }
    }

    return false;
}

// Function to check if password contains special character
bool contains_special_char(char *password) {
    int len = strlen(password);
    int i;

    for (i = 0; i < len; i++) {
        if (!((password[i] >= 'A' && password[i] <= 'Z')
                || (password[i] >= 'a' && password[i] <= 'z')
                || (password[i] >= '0' && password[i] <= '9'))) {
            return true;
        }
    }

    return false;
}

// Function to check password strength
bool is_password_strong(char *password) {
    if (strlen(password) < 8) {
        return false;
    }

    if (!contains_uppercase(password)) {
        return false;
    }

    if (!contains_lowercase(password)) {
        return false;
    }

    if (!contains_digit(password)) {
        return false;
    }

    if (!contains_special_char(password)) {
        return false;
    }

    return true;
}


int main() {
    char password[50];

    printf("Enter your password: ");
    fgets(password, 50, stdin);

    if (is_password_strong(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is not strong!\n");
    }

    return 0;
}