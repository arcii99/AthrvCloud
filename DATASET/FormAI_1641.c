//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_PASSWORD_LENGTH 100

bool isUpperCase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}

bool isLowerCase(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    return false;
}

bool isDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool isSpecialChar(char c)
{
    if ((c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= ']') || (c >= '{' && c <= '}'))
    {
        return true;
    }
    return false;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    int passwordLength;
    int upperCaseCount = 0;
    int lowerCaseCount = 0;
    int digitCount = 0;
    int specialCharCount = 0;

    printf("Enter the password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);  // read the password with spaces

    passwordLength = strlen(password) - 1; // since fgets includes the newline character, we need to subtract it from length

    if (passwordLength < 8)
    {
        printf("Password is too short (should be at least 8 characters)\n");
        return 0;
    }

    for (int i = 0; i < passwordLength; i++)
    {
        char currentChar = password[i];

        if (isUpperCase(currentChar))
        {
            upperCaseCount++;
        }
        else if (isLowerCase(currentChar))
        {
            lowerCaseCount++;
        }
        else if (isDigit(currentChar))
        {
            digitCount++;
        }
        else if (isSpecialChar(currentChar))
        {
            specialCharCount++;
        }
    }

    if (upperCaseCount < 1)
    {
        printf("Password should contain at least 1 uppercase letter\n");
    }

    if (lowerCaseCount < 1)
    {
        printf("Password should contain at least 1 lowercase letter\n");
    }

    if (digitCount < 1)
    {
        printf("Password should contain at least 1 digit\n");
    }

    if (specialCharCount < 1)
    {
        printf("Password should contain at least 1 special character (@,!,#, etc)\n");
    }

    if (upperCaseCount >= 1 && lowerCaseCount >= 1 && digitCount >= 1 && specialCharCount >= 1)
    {
        printf("Password is strong\n");
    }

    return 0;
}