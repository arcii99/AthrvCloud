//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20 // Maximum password length
#define MIN_PASSWORD_LENGTH 8 // Minimum password length

// Function that generates a random integer between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function that generates a random lowercase letter
char generateRandomLowercaseLetter() {
    return generateRandomNumber('a', 'z');
}

// Function that generates a random uppercase letter
char generateRandomUppercaseLetter() {
  return generateRandomNumber('A', 'Z');
}

// Function that generates a random digit
char generateRandomDigit() {
    return generateRandomNumber('0', '9');
}

// Function that generates a random symbol
char generateRandomSymbol() {
  char symbols[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '[', ']', '{', '}', ';', ':', ',', '.', '<', '>', '/', '?', '|', '\\'};
  int numSymbols = sizeof(symbols) / sizeof(char);
  return symbols[generateRandomNumber(0, numSymbols - 1)];
}

// Function that generates a secure password
void generatePassword(char password[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        int type = generateRandomNumber(0, 3);
        if (type == 0) {
            password[i] = generateRandomLowercaseLetter();
        } else if (type == 1) {
            password[i] = generateRandomUppercaseLetter();
        } else if (type == 2) {
            password[i] = generateRandomDigit();
        } else if (type == 3) {
            password[i] = generateRandomSymbol();
        }
    }
    password[length] = '\0';
}

// Function that checks if a password is secure
int isSecurePassword(char password[]) {
    if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int numLowercase = 0;
    int numUppercase = 0;
    int numDigits = 0;
    int numSymbols = 0;
    int i;
    for (i = 0; i < strlen(password); i++) {
        char ch = password[i];
        if (islower(ch)) {
            numLowercase++;
        } else if (isupper(ch)) {
            numUppercase++;
        } else if (isdigit(ch)) {
            numDigits++;
        } else {
            numSymbols++;
        }
    }
    return (numLowercase > 0 && numUppercase > 0 && numDigits > 0 && numSymbols > 0);
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    char password[MAX_PASSWORD_LENGTH + 1];
    int length = generateRandomNumber(MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    generatePassword(password, length);
    while (!isSecurePassword(password)) {
        generatePassword(password, length);
    }
    printf("Your Secure Password: %s\n", password);
    return 0;
}