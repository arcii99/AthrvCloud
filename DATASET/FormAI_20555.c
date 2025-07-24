//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 10

char generateRandomCharacter() {
    return (char)(rand() % 94 + 33); // ASCII 33-126 represents printable characters
}

int main(void) {
    char password[PASSWORD_LENGTH + 1]; // +1 to account for null terminator
    int i, numDigits, numUppercase, numLowercase;

    srand(time(NULL)); // seed random number generator with current time

    printf("Welcome to the Secure Password Generator!\n");
    printf("Generating a %d-character password...\n", PASSWORD_LENGTH);

    // Generate random characters for the password
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generateRandomCharacter();
    }
    password[PASSWORD_LENGTH] = '\0'; // add null terminator

    // Make sure the password contains at least 1 digit, 1 uppercase letter, and 1 lowercase letter
    numDigits = numUppercase = numLowercase = 0;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        if (isdigit(password[i])) {
            numDigits++;
        }
        else if (isupper(password[i])) {
            numUppercase++;
        }
        else if (islower(password[i])) {
            numLowercase++;
        }
    }

    // Replace random characters with digits, uppercase letters, and lowercase letters until requirements are met
    while (numDigits < 1 || numUppercase < 1 || numLowercase < 1) {
        i = rand() % PASSWORD_LENGTH;
        if (!isdigit(password[i]) && !isupper(password[i]) && !islower(password[i])) {
            if (numDigits < 1) {
                password[i] = generateRandomCharacter();
                while (!isdigit(password[i])) {
                    password[i] = generateRandomCharacter();
                }
                numDigits++;
            }
            else if (numUppercase < 1) {
                password[i] = generateRandomCharacter();
                while (!isupper(password[i])) {
                    password[i] = generateRandomCharacter();
                }
                numUppercase++;
            }
            else if (numLowercase < 1) {
                password[i] = generateRandomCharacter();
                while (!islower(password[i])) {
                    password[i] = generateRandomCharacter();
                }
                numLowercase++;
            }
        }
    }

    printf("Your new password is: %s\n", password);

    return 0;
}