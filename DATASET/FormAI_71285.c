//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12

char generateRandomChar()
{
    char randomChar;
    int charType = rand() % 4;
    
    switch(charType)
    {
        case 0:
            randomChar = rand() % 26 + 'a'; // lowercase letter
            break;
        case 1:
            randomChar = rand() % 26 + 'A'; // uppercase letter
            break;
        case 2:
            randomChar = rand() % 10 + '0'; // digit
            break;
        default:
            randomChar = rand() % 15 + 33; // special character
            break;
    }
    
    return randomChar;
}

void generatePassword(char* password)
{
    for(int i = 0; i < PASSWORD_LENGTH; i++)
    {
        password[i] = generateRandomChar();
    }
    password[PASSWORD_LENGTH] = '\0';
}

int main()
{
    srand(time(NULL)); // seeding the random number generator with the current time
    
    char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator
    
    generatePassword(password);
    
    printf("Generated Password: %s\n", password);
    
    return 0;
}