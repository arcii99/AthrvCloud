//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20 // maximum length of generated password
#define NUM_SPECIAL_CHARS 5 // number of available special characters
#define NUM_UPPERCASE_LETTERS 26 // number of available uppercase letters
#define NUM_LOWERCASE_LETTERS 26 // number of available lowercase letters
#define NUM_DIGITS 10 // number of available digits

char generateChar(const char *choices, const int numChoices) {
    int choiceIndex = rand() % numChoices;
    return choices[choiceIndex];
}

int main(void) {
    // set up character choices
    char specialChars[NUM_SPECIAL_CHARS] = {'!', '@', '#', '$', '%'};
    char uppercaseLetters[NUM_UPPERCASE_LETTERS];
    char lowercaseLetters[NUM_LOWERCASE_LETTERS];
    char digits[NUM_DIGITS];
    for (int i = 0; i < NUM_UPPERCASE_LETTERS; ++i) {
        uppercaseLetters[i] = 'A' + i;
    }
    for (int i = 0; i < NUM_LOWERCASE_LETTERS; ++i) {
        lowercaseLetters[i] = 'a' + i;
    }
    for (int i = 0; i < NUM_DIGITS; ++i) {
        digits[i] = '0' + i;
    }

    // seed random number generator
    srand(time(NULL));

    // get desired password length from user
    int passwordLength;
    printf("Enter desired password length (must be between 1 and %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &passwordLength);
    if (passwordLength < 1 || passwordLength > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return EXIT_FAILURE;
    }

    // generate password
    char password[MAX_PASSWORD_LENGTH + 1] = {'\0'}; // make sure to null-terminate the string
    int numSpecialChars = 0;
    int numUppercaseLetters = 0;
    int numLowercaseLetters = 0;
    int numDigits = 0;
    for (int i = 0; i < passwordLength; ++i) {
        char c;
        if (i == 0) { // first character must be a letter
            c = generateChar(uppercaseLetters, NUM_UPPERCASE_LETTERS + NUM_LOWERCASE_LETTERS);
        } else {
            int numChoices = 0;
            char choices[NUM_SPECIAL_CHARS + NUM_UPPERCASE_LETTERS + NUM_LOWERCASE_LETTERS + NUM_DIGITS] = {'\0'};
            if (numSpecialChars < NUM_SPECIAL_CHARS) {
                choices[numChoices++] = specialChars[0];
            }
            if (numUppercaseLetters < passwordLength / 2) { // ensure at least half the letters are uppercase
                choices[numChoices++] = generateChar(uppercaseLetters, NUM_UPPERCASE_LETTERS);
            }
            if (numLowercaseLetters < passwordLength / 2) { // ensure at least half the letters are lowercase
                choices[numChoices++] = generateChar(lowercaseLetters, NUM_LOWERCASE_LETTERS);
            }
            if (numDigits < passwordLength / 3) { // ensure at least a third of characters are digits
                choices[numChoices++] = generateChar(digits, NUM_DIGITS);
            }
            choices[numChoices++] = generateChar(uppercaseLetters, NUM_UPPERCASE_LETTERS + NUM_LOWERCASE_LETTERS);
            c = generateChar(choices, numChoices);
            if (isdigit(c)) { numDigits++; }
            else if (isupper(c)) { numUppercaseLetters++; }
            else if (islower(c)) { numLowercaseLetters++; }
            else { numSpecialChars++; }
        }
        password[i] = c;
    }

    printf("Generated password: %s\n", password);
    return EXIT_SUCCESS;
}