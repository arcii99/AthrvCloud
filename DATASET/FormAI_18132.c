//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

char* GeneratePassword(char* password);

int main()
{
    char password[PASSWORD_LENGTH + 1];

    printf("Your new password is: %s\n", GeneratePassword(password));

    return 0;
}

char* GeneratePassword(char* password)
{
    char symbols[] =
    {
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', '{', ']', '}', '\\', '|', ';', ':', '\'', '\"', ',', '<', '.', '>', '/', '?'
    };

    char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";

    srand((unsigned)time(NULL));

    int i;
    int numSymbols = sizeof(symbols) / sizeof(symbols[0]);
    int numLowercaseLetters = sizeof(lowercaseLetters) / sizeof(lowercaseLetters[0]) - 1;
    int numUppercaseLetters = sizeof(uppercaseLetters) / sizeof(uppercaseLetters[0]) - 1;
    int numNumbers = sizeof(numbers) / sizeof(numbers[0]) - 1;

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        int passwordType = rand() % 4;

        switch (passwordType)
        {
            case 0:
                password[i] = symbols[rand() % numSymbols];
                break;
            case 1:
                password[i] = lowercaseLetters[rand() % numLowercaseLetters];
                break;
            case 2:
                password[i] = uppercaseLetters[rand() % numUppercaseLetters];
                break;
            case 3:
                password[i] = numbers[rand() % numNumbers];
                break;
        }
    }

    password[PASSWORD_LENGTH] = '\0';

    return password;
}