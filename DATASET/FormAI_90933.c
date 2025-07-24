//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[20];
    int length, i;
    int upper = 0, lower = 0, number = 0, special = 0;

    printf("Enter password: ");
    fgets(password, 20, stdin);
    length = strlen(password) - 1;

    // Check for minimum length
    if (length < 8)
    {
        printf("The password must be at least 8 characters long.\n");
        return 0;
    }

    for (i = 0; i < length; i++)
    {
        // Check for uppercase letters
        if (isupper(password[i]))
        {
            upper = 1;
        }
        // Check for lowercase letters
        else if (islower(password[i]))
        {
            lower = 1;
        }
        // Check for digits
        else if (isdigit(password[i]))
        {
            number = 1;
        }
        // Check for special characters
        else
        {
            special = 1;
        }
    }

    // Check for all four conditions
    if (upper && lower && number && special)
    {
        printf("The password is strong.\n");
    }
    else
    {
        printf("The password is weak. It must contain at least one uppercase letter, one lowercase letter, one digit and one special character.\n");
    }

    return 0;
}