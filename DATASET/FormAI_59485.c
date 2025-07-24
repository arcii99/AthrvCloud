//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12

// Function to generate a random uppercase letter
char random_uppercase() {
    return 'A' + (rand() % 26);
}

// Function to generate a random lowercase letter
char random_lowercase() {
    return 'a' + (rand() % 26);
}

// Function to generate a random digit
char random_digit() {
    return '0' + (rand() % 10);
}

// Function to generate a random symbol
char random_symbol() {
    char symbols[] = "!@#$%^&*()_-+={}[]\\|;:'\"<>,.?/~`";
    return symbols[rand() % sizeof(symbols)];
}

// Function to generate a random character of any type
char random_char() {
    int choice = rand() % 4;
    switch (choice) {
        case 0: return random_uppercase();
        case 1: return random_lowercase();
        case 2: return random_digit();
        case 3: return random_symbol();
    }
}

int main() {
    // Seed the random number generator
    srand((unsigned int) time(NULL));

    // Generate the password
    char password[PASSWORD_LENGTH+1];
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = random_char();
    }
    password[PASSWORD_LENGTH] = '\0';

    // Verify password strength
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_symbol = 0;
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        }
        if (islower(password[i])) {
            has_lowercase = 1;
        }
        if (isdigit(password[i])) {
            has_digit = 1;
        }
        if (!isalnum(password[i])) {
            has_symbol = 1;
        }
    }

    // Ensure password meets requirements
    if (!has_uppercase || !has_lowercase || !has_digit || !has_symbol) {
        // Replace random character until all requirements are met
        do {
            int index = rand() % PASSWORD_LENGTH;
            password[index] = random_char();
            has_uppercase = has_lowercase = has_digit = has_symbol = 0;
            for (int i = 0; i < PASSWORD_LENGTH; i++) {
                if (isupper(password[i])) {
                    has_uppercase = 1;
                }
                if (islower(password[i])) {
                    has_lowercase = 1;
                }
                if (isdigit(password[i])) {
                    has_digit = 1;
                }
                if (!isalnum(password[i])) {
                    has_symbol = 1;
                }
            }
        } while (!has_uppercase || !has_lowercase || !has_digit || !has_symbol);
    }

    // Print the password
    printf("Your secure password is: %s\n", password);
    return 0;
}