//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PASSWORD_LENGTH 12

int main()
{
    // Welcome message
    printf("Welcome to the Secure Password Generator!\n");

    // Characters for password generation
    char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char specialChars[] = "!@#$%^&*()";

    // Length of each characters array
    int lowerLen = sizeof(lowercaseLetters)-1;
    int upperLen = sizeof(uppercaseLetters)-1;
    int digitLen = sizeof(digits)-1;
    int specialLen = sizeof(specialChars)-1;

    // Set random seed
    srand(time(NULL));

    // Generate password
    char password[PASSWORD_LENGTH+1]; // Add 1 for null terminator
    for(int i=0; i<PASSWORD_LENGTH; i++)
    {
        int charType = rand() % 4;
        switch(charType)
        {
            case 0:
                password[i] = lowercaseLetters[rand() % lowerLen];
                break;
            case 1:
                password[i] = uppercaseLetters[rand() % upperLen];
                break;
            case 2:
                password[i] = digits[rand() % digitLen];
                break;
            case 3:
                password[i] = specialChars[rand() % specialLen];
                break;
            default:
                break;
        }
    }
    password[PASSWORD_LENGTH] = '\0'; // Null terminator

    // Print generated password
    printf("Your Secure Password: %s\n", password);

    return 0;
}