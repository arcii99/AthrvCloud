//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20 // maximum password length
#define MIN_LENGTH 8 // minimum password length
#define MAX_CHARACTER_SET_LENGTH 62 // maximum number of possible characters (az+AZ+09)
#define ALPHABET_OFFSET 65 // ASCII offset for uppercase alphabets

char generateRandomChar() {
    char randomChar;
    int randomNum;
    do {
        randomNum = rand() % MAX_CHARACTER_SET_LENGTH;
    } while (randomNum < 0 || randomNum > MAX_CHARACTER_SET_LENGTH);
    if (randomNum < 10) {
        randomChar = randomNum + '0'; // ASCII value for numbers 0-9
    } else if (randomNum < 36) {
        randomChar = randomNum - 10 + 'a'; // ASCII value for lowercase alphabets
    } else {
        randomChar = randomNum - 36 + ALPHABET_OFFSET; // ASCII value for uppercase alphabets
    }
    return randomChar;
}

void generatePassword(char* password) {
    int passwordLength;
    do {
        passwordLength = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH;
    } while (passwordLength < MIN_LENGTH || passwordLength > MAX_LENGTH);
    for (int i = 0; i < passwordLength; i++) {
        password[i] = generateRandomChar();
    }
    password[passwordLength] = '\0';
}

int main() {
    srand(time(NULL)); // seeding random number generator with current time
    char password[MAX_LENGTH + 1];
    for (int i = 1; i <= 10; i++) {
        generatePassword(password);
        printf("Password #%d: %s\n", i, password);
    }
    return 0;
}