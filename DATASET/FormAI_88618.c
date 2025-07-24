//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function Prototype declarations
int hasUpperCase(char *password);
int hasLowerCase(char *password);
int hasDigit(char *password);
int hasSpecialChar(char *password);
int passwordLength(char *password);
int passwordScore(char *password);

// Main Function
int main() {
    char password[20];
    printf("Enter password: ");
    fgets(password, 20, stdin);
    password[strcspn(password, "\n")] = 0;
    int score = passwordScore(password);
    if (score >= 3) {
        printf("Strong Password\n");
    }
    else if (score >= 2) {
        printf("Moderate Password\n");
    }
    else {
        printf("Weak Password\n");
    }
    return 0;
}

// Function to check for uppercase letter
int hasUpperCase(char *password) {
    while (*password) {
        if (isupper(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check for lowercase letter
int hasLowerCase(char *password) {
    while (*password) {
        if (islower(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check for digit
int hasDigit(char *password) {
    while (*password) {
        if (isdigit(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check for special character
int hasSpecialChar(char *password) {
    while (*password) {
        if (!isalnum(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check password length
int passwordLength(char *password) {
    return strlen(password);
}

// The main function to calculate password score
int passwordScore(char *password) {
    int score = 0;
    if (hasUpperCase(password)) {
        score++;
    }
    if (hasLowerCase(password)) {
        score++;
    }
    if (hasDigit(password)) {
        score++;
    }
    if (hasSpecialChar(password)) {
        score++;
    }
    if (passwordLength(password) >= 8) {
        score++;
    }
    return score;
}