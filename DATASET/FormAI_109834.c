//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32
#define MAX_SPECIAL_CHARACTERS 5
#define MAX_DIGITS 5

void generateRandomPassword(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH + 1]; // +1 to account for null terminator
    srand(time(0)); // Seed the random number generator with the current time

    printf("Secure Password Generator\n");
    printf("-------------------------\n");
    generateRandomPassword(password);
    printf("Generated Password: %s\n", password);
    return 0;
}

void generateRandomPassword(char *password) {
    char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char specialCharacters[] = "!@#$%^&*()_+-=[]{};':\",./<>?\\|";
    char digits[] = "0123456789";
    int specialCharacterIndices[MAX_SPECIAL_CHARACTERS];
    int digitIndices[MAX_DIGITS];
    int uppercaseLetterIndex, lowercaseLetterIndex, i;

    // Initialize all indices to -1 to indicate they have not been set yet
    for (i = 0; i < MAX_SPECIAL_CHARACTERS; i++) {
        specialCharacterIndices[i] = -1;
    }
    for (i = 0; i < MAX_DIGITS; i++) {
        digitIndices[i] = -1;
    }

    // Generate a random uppercase letter
    uppercaseLetterIndex = rand() % strlen(uppercaseLetters);
    password[0] = uppercaseLetters[uppercaseLetterIndex];

    // Generate a random lowercase letter
    lowercaseLetterIndex = rand() % strlen(lowercaseLetters);
    password[1] = lowercaseLetters[lowercaseLetterIndex];

    // Generate random special characters
    for (i = 0; i < MAX_SPECIAL_CHARACTERS; i++) {
        int index = rand() % strlen(specialCharacters);
        // Make sure we don't add a duplicate special character
        while (index == uppercaseLetterIndex || index == lowercaseLetterIndex ||
               index == specialCharacterIndices[0] || index == specialCharacterIndices[1] ||
               index == specialCharacterIndices[2] || index == specialCharacterIndices[3] ||
               index == specialCharacterIndices[4]) {
            index = rand() % strlen(specialCharacters);
        }
        specialCharacterIndices[i] = index;
        password[2 + i] = specialCharacters[index];
    }

    // Generate random digits
    for (i = 0; i < MAX_DIGITS; i++) {
        int index = rand() % strlen(digits);
        // Make sure we don't add a duplicate digit
        while (index == uppercaseLetterIndex || index == lowercaseLetterIndex ||
               index == specialCharacterIndices[0] || index == specialCharacterIndices[1] ||
               index == specialCharacterIndices[2] || index == specialCharacterIndices[3] ||
               index == specialCharacterIndices[4] || index == digitIndices[0] ||
               index == digitIndices[1] || index == digitIndices[2] || index == digitIndices[3] ||
               index == digitIndices[4]) {
            index = rand() % strlen(digits);
        }
        digitIndices[i] = index;
        password[2 + MAX_SPECIAL_CHARACTERS + i] = digits[index];
    }

    // Shuffle the password characters using the Fisher-Yates algorithm
    int j;
    for (i = MAX_PASSWORD_LENGTH - 1; i > 0; i--) {
        j = rand() % (i + 1);

        // Swap password[i] and password[j]
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Add the null terminator to the end of the password string
    password[MAX_PASSWORD_LENGTH] = '\0';
}