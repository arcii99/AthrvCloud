//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 25
#define MIN_LENGTH 8
#define MAX_SPECIAL 5
#define MAX_UPPER 5
#define MAX_LOWER 5
#define MAX_DIGITS 5

char generateRandomCharacter(char min, char max)
{
    return (rand() % (max - min + 1)) + min;
}

void generateRandomString(char* output, int minLength, int maxLength, int maxSpecial, int maxUpper, int maxLower, int maxDigits)
{
    int i, specialCount = 0, upperCount = 0, lowerCount = 0, digitsCount = 0;

    // Set seed for random number generator
    srand(time(0));

    // Generate random length
    int length = rand() % (maxLength - minLength + 1) + minLength;

    // Fill the string with random characters
    for (i = 0; i < length; i++) {
        char c;

        // Ensure maximum special characters
        if (specialCount >= maxSpecial) {
            c = generateRandomCharacter('A', 'z');
        }
        else {
            // Generate a random character
            int type = rand() % 4;

            if (type == 0) {
                c = generateRandomCharacter('A', 'Z'); // Upper case letter
                upperCount++;
            }
            else if (type == 1) {
                c = generateRandomCharacter('a', 'z'); // Lower case letter
                lowerCount++;
            }
            else if (type == 2) {
                c = generateRandomCharacter('0', '9'); // Digit
                digitsCount++;
            }
            else {
                c = generateRandomCharacter('!', '/'); // Special character
                specialCount++;
            }
        }

        output[i] = c;
    }

    output[length] = '\0';

    // Ensure minimum requirements
    if (specialCount < maxSpecial || upperCount < maxUpper || lowerCount < maxLower || digitsCount < maxDigits) {
        generateRandomString(output, minLength, maxLength, maxSpecial, maxUpper, maxLower, maxDigits);
    }
}

int main()
{
    char password[MAX_LENGTH + 1];

    generateRandomString(password, MIN_LENGTH, MAX_LENGTH, MAX_SPECIAL, MAX_UPPER, MAX_LOWER, MAX_DIGITS);

    printf("Your generated secure password is: %s\n", password);

    return 0;
}