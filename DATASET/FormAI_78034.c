//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12 // desired length of password
#define UPPER_LIMIT 126   // upper limit of ASCII values for printable characters
#define LOWER_LIMIT 33    // lower limit of ASCII values for printable characters

// function to generate a random integer between specified limits
int randomInt(int lower, int upper)
{
    return rand() % (upper - lower + 1) + lower;
}

// function to generate a random password with specified length
void generatePassword(char password[]) 
{
    for (int i = 0; i < PASSWORD_LENGTH; i++) 
    {
        password[i] = (char)randomInt(LOWER_LIMIT, UPPER_LIMIT);
    }
    password[PASSWORD_LENGTH] = '\0'; // terminating the string
}

int main()
{
    // seeding the random number generator
    srand(time(0));
    
    char password[PASSWORD_LENGTH + 1]; // adding 1 for the null terminator
    
    // generating a secure password
    generatePassword(password);
    
    // checking if the password satisfies all the conditions of a secure password
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = 1;
        else if (password[i] >= 'a' && password[i] <= 'z') hasLower = 1;
        else if (password[i] >= '0' && password[i] <= '9') hasDigit = 1;
        else hasSpecial = 1;
    }
    
    // if password doesn't satisfy all the conditions, regenerate a new one
    while (!(hasUpper && hasLower && hasDigit && hasSpecial)) 
    {
        generatePassword(password);
        length = strlen(password);
        hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
        for (int i = 0; i < length; i++)
        {
            if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = 1;
            else if (password[i] >= 'a' && password[i] <= 'z') hasLower = 1;
            else if (password[i] >= '0' && password[i] <= '9') hasDigit = 1;
            else hasSpecial = 1;
        }
    }
    
    // printing the generated secure password
    printf("Your secure password is: %s\n", password);
    
    return 0;
}