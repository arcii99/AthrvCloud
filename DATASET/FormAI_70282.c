//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_PASSWORD_LENGTH 50

int main()
{
    char password[MAX_PASSWORD_LENGTH + 1], ch;
    int length = 0, upperCase = 0, lowerCase = 0, number = 0, specialCharacter = 0;

    printf("Please enter a password for strength check:\n");

    while ((ch = getchar()) != '\n')
    {
        if (length > MAX_PASSWORD_LENGTH)
        {
            printf("Password is too long!\n");
            exit(1);
        }
        password[length++] = ch;
    }

    password[length] = '\0';

    if (length < 8)
        printf("Your password should contain at least 8 characters\n");
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (isupper(password[i]))
                upperCase++;
            else if (islower(password[i]))
                lowerCase++;
            else if (isdigit(password[i]))
                number++;
            else
                specialCharacter++;
        }

        printf("\nPassword Strength Checker:\n");

        if (upperCase && lowerCase && number && specialCharacter)
            printf("Password is strong!\n");
        else if ((upperCase && lowerCase && specialCharacter) || (upperCase && lowerCase && number) || (lowerCase && number && specialCharacter) || (upperCase && number && specialCharacter))
            printf("Password is moderately strong.\nA good password should contain uppercase and lowercase letters, digits, and special characters.\n");
        else
            printf("Password is weak!\nA good password should contain uppercase and lowercase letters, digits, and special characters.\n");
    }

    printf("\nThank you for using our Password Strength Checker!\n");

    return 0;
}