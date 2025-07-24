//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

#define MAX_LENGTH 20   // Maximum length of password
#define MIN_LENGTH 8    // Minimum length of password
#define SPECIAL_CHAR "!@#$%^&*()"
#define NUM_DIGITS 3    // Number of digits required in password

// Function to generate random integer between two numbers (inclusive)
int generateRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

// Function to generate random special character from a given string
char generateRandomSpecialChar() {
    int index = rand() % strlen(SPECIAL_CHAR);
    char specialChar = SPECIAL_CHAR[index];
    return specialChar;
}

// Function to generate secure password
int generateSecurePassword(char *password) {
    int length = generateRandomNumber(MIN_LENGTH, MAX_LENGTH);
    int numDigits = 0;
    int numSpecialChars = 0;
    int numLowercaseChars = 0;
    int numUppercaseChars = 0;

    // Seed random number generator
    srand(time(NULL));

    // Generate password with given length
    for(int i = 0; i < length; i++) {
        // Generate random character
        int choice = generateRandomNumber(0, 2);
        char randomChar;

        switch(choice) {
            case 0:
                // Generate random digit
                if(numDigits < NUM_DIGITS) {
                    randomChar = generateRandomNumber(48, 57);
                    numDigits++;
                } else {
                    i--;
                    continue;
                }
                break;

            case 1:
                // Generate random special character
                if(numSpecialChars < length - NUM_DIGITS - 2 && length - numUppercaseChars - numLowercaseChars - numSpecialChars - numDigits > 1) {
                    randomChar = generateRandomSpecialChar();
                    numSpecialChars++;
                } else {
                    i--;
                    continue;
                }
                break;
            
            case 2:
                // Generate random alphabet
                int alphabetType = generateRandomNumber(0, 2);
                if(alphabetType == 0 && numLowercaseChars < length - NUM_DIGITS - 2 && length - numUppercaseChars - numLowercaseChars - numSpecialChars - numDigits > 1) {
                    // Generate random lowercase alphabet
                    randomChar = generateRandomNumber(97, 122);
                    numLowercaseChars++;
                } else if(alphabetType == 1 && numUppercaseChars < length - NUM_DIGITS - 2 && length - numUppercaseChars - numLowercaseChars - numSpecialChars - numDigits > 1) {
                    // Generate random uppercase alphabet
                    randomChar = generateRandomNumber(65, 90);
                    numUppercaseChars++;
                } else {
                    i--;
                    continue;
                }
                break;
        }

        password[i] = randomChar;
    }

    // Add null terminator to password string
    password[length] = '\0';

    return 0;
}

// Main function
int main() {
    char password[MAX_LENGTH+1];

    // Generate secure password
    generateSecurePassword(password);

    // Print generated password
    printf("Secure password: %s\n", password);

    return 0;
}