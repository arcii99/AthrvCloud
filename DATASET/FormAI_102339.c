//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 12 // Define the length of the password
#define NUM_LOWERCASE 2 // Define the number of lowercase letters
#define NUM_UPPERCASE 2 // Define the number of uppercase letters
#define NUM_DIGITS 2 // Define the number of digits
#define NUM_SPECIAL_CHARS 2 // Define the number of special characters

/* Function declarations */
int generateRandomInt(int min, int max);
void generatePassword(char* password, int length);
void swapChars(char* a, char* b);

int main()
{
    char password[PASSWORD_LENGTH + 1]; // Initialize password array
    generatePassword(password, PASSWORD_LENGTH); // Generate the password
    printf("Your secure password is: %s\n", password); // Print the password
    return 0;
}

/* Generates a random integer between min and max, inclusive */
int generateRandomInt(int min, int max)
{
    srand(time(NULL)); // Seed the random number generator
    return rand() % (max - min + 1) + min; // Return the random integer
}

/* Generates a secure password with the specified length */
void generatePassword(char* password, int length)
{
    /* Initialize variables */
    int numLowercase = 0;
    int numUppercase = 0;
    int numDigits = 0;
    int numSpecialChars = 0;

    /* Generate the required number of each type of character */
    while (numLowercase < NUM_LOWERCASE)
    {
        char c = generateRandomInt(97, 122); // Generate a lowercase letter (ASCII range 97-122)
        if(islower(c))
        {
            password[numLowercase] = c; // Add the lowercase character to the password
            numLowercase++; // Increment the counter
        }
    }

    while (numUppercase < NUM_UPPERCASE)
    {
        char c = generateRandomInt(65, 90); // Generate an uppercase letter (ASCII range 65-90)
        if(isupper(c))
        {
            password[numLowercase + numUppercase] = c; // Add the uppercase character to the password
            numUppercase++; // Increment the counter
        }
    }

    while (numDigits < NUM_DIGITS)
    {
        char c = generateRandomInt(48, 57); // Generate a digit (ASCII range 48-57)
        if(isdigit(c))
        {
            password[numLowercase + numUppercase + numDigits] = c; // Add the digit to the password
            numDigits++; // Increment the counter
        }
    }

    while (numSpecialChars < NUM_SPECIAL_CHARS)
    {
        char c = generateRandomInt(33, 47); // Generate a special character (ASCII range 33-47)
        if(!isdigit(c) && !isalpha(c)) // Check if the character is not a digit or an alphabet
        {
            password[numLowercase + numUppercase + numDigits + numSpecialChars] = c; // Add the special character to the password
            numSpecialChars++; // Increment the counter
        }
    }

    /* Fill the remaining characters of the password with random characters */
    int remainingChars = length - (numLowercase + numUppercase + numDigits + numSpecialChars); // Calculate the remaining characters
    for (int i = numLowercase + numUppercase + numDigits + numSpecialChars; i < length; i++)
    {
        char c = generateRandomInt(33, 127); // Generate a random character (ASCII range 33-127)
        password[i] = c; // Add the random character to the password
    }

    /* Shuffle the characters of the password */
    for (int i = length - 1; i > 0; i--)
    {
        int j = generateRandomInt(0, i); // Generate a random index between 0 and i
        swapChars(&password[i], &password[j]); // Swap the characters at the i-th and j-th positions
    }
}

/* Swaps the values of two characters */
void swapChars(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}