//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to generate a random character from given set of characters
char randomChar(char *charSet, int charSetLength)
{
    int randomIndex = rand() % charSetLength; // generate random index within charSet
    return charSet[randomIndex];
}

// Function to generate a secure password
void generatePassword(int passwordLength)
{
    char *lowerCaseLetters = "abcdefghijklmnopqrstuvwxyz";
    char *upperCaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *digits = "0123456789";
    char *specialChars = "!@#$%^&*()_-+={}[]|\\:;<>,.?/";

    int lowerCaseLettersLength = strlen(lowerCaseLetters);
    int upperCaseLettersLength = strlen(upperCaseLetters);
    int digitsLength = strlen(digits);
    int specialCharsLength = strlen(specialChars);

    char password[passwordLength + 1]; // +1 for null terminator
    int currentIndex = 0;

    // Add at least one lower case letter
    password[currentIndex++] = randomChar(lowerCaseLetters, lowerCaseLettersLength);

    // Add at least one upper case letter
    password[currentIndex++] = randomChar(upperCaseLetters, upperCaseLettersLength);

    // Add at least one digit
    password[currentIndex++] = randomChar(digits, digitsLength);

    // Add at least one special character
    password[currentIndex++] = randomChar(specialChars, specialCharsLength);

    // Add remaining characters
    for (; currentIndex < passwordLength; currentIndex++)
    {
        char *charSet;
        int charSetLength;

        // Choose a character set randomly
        int randomSet = rand() % 4;
        switch (randomSet)
        {
            case 0:
            default:
                charSet = lowerCaseLetters;
                charSetLength = lowerCaseLettersLength;
                break;
            case 1:
                charSet = upperCaseLetters;
                charSetLength = upperCaseLettersLength;
                break;
            case 2:
                charSet = digits;
                charSetLength = digitsLength;
                break;
            case 3:
                charSet = specialChars;
                charSetLength = specialCharsLength;
                break;
        }

        password[currentIndex] = randomChar(charSet, charSetLength);
    }

    password[currentIndex] = '\0'; // add null terminator at the end

    printf("\nYour secure password is: %s\n\n", password);
}

// Function to check whether provided input is a positive integer or not
int isPositiveInteger(char *input)
{
    int length = strlen(input);

    for (int i = 0; i < length; i++)
    {
        if (!isdigit(input[i]))
        {
            return 0; // not a positive integer
        }
    }

    return 1; // positive integer
}

int main()
{
    time_t t;
    srand((unsigned) time(&t)); // seed the random number generator with current time

    printf("==== Secure Password Generator ====\n\n");

    int passwordLength = 0;

    // Get password length from user
    while (passwordLength <= 0)
    {
        char input[256];
        printf("Enter desired password length (should be a positive integer): ");
        fgets(input, 256, stdin); // get user input as string
        input[strcspn(input, "\n")] = '\0'; // remove trailing newline character

        if (isPositiveInteger(input))
        {
            passwordLength = atoi(input); // convert input to integer
        }
        else
        {
            printf("Error! Please enter a positive integer.\n");
        }
    }

    generatePassword(passwordLength);

    return 0;
}