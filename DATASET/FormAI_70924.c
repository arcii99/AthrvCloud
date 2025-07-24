//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 15 // The password length can be modified to any desired value

int main()
{
    int i, randomInt;
    char password[PASSWORD_LENGTH + 1]; // The password length + 1 for the null terminator

    srand(time(NULL)); // Initialize the random seed

    // Define the character sets to be used in the password
    char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{},.<>?";

    // Generate the password
    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        randomInt = rand() % 4; // Generate a random integer from 0 to 3

        // Choose a random character from a random character set based on the random integer
        switch (randomInt)
        {
            case 0:
                password[i] = uppercaseLetters[rand() % strlen(uppercaseLetters)];
                break;
            case 1:
                password[i] = lowercaseLetters[rand() % strlen(lowercaseLetters)];
                break;
            case 2:
                password[i] = digits[rand() % strlen(digits)];
                break;
            case 3:
                password[i] = symbols[rand() % strlen(symbols)];
                break;
            default:
                break;
        }
    }

    password[PASSWORD_LENGTH] = '\0'; // Add the null terminator to the end of the string

    // Print the password
    printf("Your generated password is: %s\n", password);

    return 0;
}