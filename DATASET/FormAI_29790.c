//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* Function to check password length */
bool checkLength(char *password) {
    int length = strlen(password);
    if (length >= 8) {
        return true;
    } else {
        return false;
    }
}

/* Function to check for lowercase letters */
bool checkLowercase(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

/* Function to check for uppercase letters */
bool checkUppercase(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

/* Function to check for digits */
bool checkDigits(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

/* Function to check for special characters */
bool checkSpecial(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

/* Main function */
int main() {
    char password[100];
    bool valid = false;
    
    while (!valid) {
        printf("Please enter your password: ");
        fgets(password, 100, stdin);
        password[strcspn(password, "\n")] = 0;  // remove newline character
        
        if (!checkLength(password)) {
            printf("Your password must be at least 8 characters long.\n");
        } else if (!checkLowercase(password)) {
            printf("Your password must contain at least one lowercase letter.\n");
        } else if (!checkUppercase(password)) {
            printf("Your password must contain at least one uppercase letter.\n");
        } else if (!checkDigits(password)) {
            printf("Your password must contain at least one digit.\n");
        } else if (!checkSpecial(password)) {
            printf("Your password must contain at least one special character.\n");
        } else {
            printf("Your password is strong!\n");
            valid = true;
        }
    }
    
    return 0;
}