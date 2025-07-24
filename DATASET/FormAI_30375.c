//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[50];
    int length, i, upper, lower, digit, special;
    int score = 0;

    printf("Welcome to the Password Strength Checker!\n\n");
    printf("Please enter a password to check its strength:\n");
    fgets(password, 50, stdin);
    length = strlen(password);

    // Password length check
    if (length >= 8 && length <= 15)
    {
        printf("\nPassword length:\t\t\t[Passed]\n");
        score++;
    }
    else
    {
        printf("\nPassword length:\t\t\t[Failed]\n");
    }

    // Character type check
    upper = lower = digit = special = 0;
    for (i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            upper++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            lower++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            digit++;
        }
        else
        {
            special++;
        }
    }

    if (upper >= 1 && lower >= 1 && digit >= 1 && special >= 1)
    {
        printf("Character types:\t\t\t[Passed]\n");
        score++;
    }
    else
    {
        printf("Character types:\t\t\t[Failed]\n");
    }

    // Repeated character check
    for (i = 0; i < length; i++)
    {
        int j, count = 0;
        for (j = 0; j < length; j++)
        {
            if (password[i] == password[j])
            {
                count++;
            }
        }
        if (count > 1)
        {
            printf("Repeated characters:\t\t\t[Failed]\n");
            break;
        }
    }

    if (i == length)
    {
        printf("Repeated characters:\t\t\t[Passed]\n");
        score++;
    }

    // Score display
    printf("\nPassword strength score:\t\t%d out of 3\n", score);

    return 0;
}