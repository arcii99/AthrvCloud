//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

const int LENGTH = 12;

char generateRandomChar() {
    int randomNum = rand() % 62;
    if (randomNum < 26) {
        return 'a' + randomNum;
    } else if (randomNum < 52) {
        return 'A' + (randomNum - 26);
    } else {
        return '0' + (randomNum - 52);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char password[LENGTH + 1]; // Allocate space for password plus null terminator

    // Generate a random password
    for (int i = 0; i < LENGTH; i++) {
        password[i] = generateRandomChar();
    }
    password[LENGTH] = '\0'; // Add null terminator to end of string

    // Check that password contains at least one uppercase letter, one lowercase letter, and one digit
    int hasLowercase = 0;
    int hasUppercase = 0;
    int hasDigit = 0;
    for (int i = 0; i < LENGTH; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        }
    }

    // If password is not valid, randomly replace characters until it is valid
    while (!hasLowercase || !hasUppercase || !hasDigit) {
        int indexToReplace = rand() % LENGTH;
        password[indexToReplace] = generateRandomChar();

        // Check again for required characters
        hasLowercase = 0;
        hasUppercase = 0;
        hasDigit = 0;
        for (int i = 0; i < LENGTH; i++) {
            if (islower(password[i])) {
                hasLowercase = 1;
            } else if (isupper(password[i])) {
                hasUppercase = 1;
            } else if (isdigit(password[i])) {
                hasDigit = 1;
            }
        }
    }

    printf("Your new secure password is: %s\n", password);

    return 0;
}