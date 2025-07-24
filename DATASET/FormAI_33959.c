//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

char symbols[] = "!@#$%^&*()_-+={}[]\\|:;\"'<>,.?/"; // Special characters
char upperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Uppercase letters
char lowercase[] = "abcdefghijklmnopqrstuvwxyz"; // Lowercase letters
char numbers[] = "0123456789"; // Numbers

void shuffle(char *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            char t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

char generateRandomCharacter(const char* characterSet, const int length) {
    return characterSet[rand() % length];
}

char* generateSecurePassword(const int passwordLength, const int numSymbols) {
    srand(time(NULL)); // Initialize random number generator
    char* password = (char*) malloc(MAX_PASSWORD_LENGTH * sizeof(char)); // Allocate memory for password

    // Generate random characters
    for (int i = 0; i < passwordLength; i++) {
        if (i < numSymbols) {
            password[i] = generateRandomCharacter(symbols, strlen(symbols));
        } else if (i < passwordLength - 2) {
            password[i] = generateRandomCharacter(numbers, strlen(numbers));
        } else {
            if (rand() % 2 == 0) {
                password[i] = generateRandomCharacter(upperCase, strlen(upperCase));
            } else {
                password[i] = generateRandomCharacter(lowercase, strlen(lowercase));
            }
        }
    }

    shuffle(password, passwordLength); // Shuffle the password characters

    return password;
}

int main() {
    int length, numSymbols;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Enter the length of the password you would like to generate (up to 20 characters): ");
    scanf("%d", &length);

    printf("Enter the number of special characters you would like in your password: ");
    scanf("%d", &numSymbols);

    // Validate user input
    if (length < 1 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Password must be between 1 and 20 characters long.\n");
        return 1;
    }

    if (numSymbols < 0 || numSymbols > length - 2) {
        printf("Invalid number of special characters. Password must contain at least 1 and at most %d special character(s).\n", length - 2);
        return 1;
    }

    char* password = generateSecurePassword(length, numSymbols);

    printf("Your new secure password is: %s\n", password);

    free(password); // Free memory allocated for password

    return 0;
}