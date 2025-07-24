//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool containsLowercase(char password[]);
bool containsUppercase(char password[]);
bool containsDigit(char password[]);
bool containsSymbol(char password[]);
bool isStrong(char password[]);
void passwordPrompt();

int main()
{
    passwordPrompt();
    return 0;
}

// Function to check if password contains lowercase letters
bool containsLowercase(char password[])
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (islower(password[i]))
        {
            return true;
        }
    }
    return false;
}

// Function to check if password contains uppercase letters
bool containsUppercase(char password[])
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            return true;
        }
    }
    return false;
}

// Function to check if password contains digits
bool containsDigit(char password[])
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (isdigit(password[i]))
        {
            return true;
        }
    }
    return false;
}

// Function to check if password contains symbols
bool containsSymbol(char password[])
{
    for (int i = 0; i < strlen(password); i++)
    {
        if (!isalnum(password[i]))
        {
            return true;
        }
    }
    return false;
}

// Function to check if password is strong
bool isStrong(char password[])
{
    int strength = 0;
    if (containsLowercase(password))
    {
        strength++;
    }
    if (containsUppercase(password))
    {
        strength++;
    }
    if (containsDigit(password))
    {
        strength++;
    }
    if (containsSymbol(password))
    {
        strength++;
    }
    if (strlen(password) >= 8 && strength >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to prompt user for password
void passwordPrompt()
{
    char password[50];
    printf("Enter your password: ");
    fgets(password, 50, stdin);
    password[strcspn(password, "\n")] = 0;
    if (isStrong(password))
    {
        printf("Your password is strong!\n");
    }
    else
    {
        printf("Your password is not strong!\n");
    }
}