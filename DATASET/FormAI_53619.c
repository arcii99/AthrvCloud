//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char password[50], c;
    int length, upper = 0, lower = 0, digits = 0, symbols = 0, strength = 0;

    printf("Enter the password to check its strength: ");
    fgets(password, 50, stdin);
    length = strlen(password) - 1;

    for (int i = 0; i < length; i++)
    {
        c = password[i];

        // Count uppercase letters
        if (isupper(c))
            upper++;

        // Count lowercase letters
        if (islower(c))
            lower++;

        // Count digits
        if (isdigit(c))
            digits++;

        // Count symbols
        if (isprint(c) && !isalnum(c))
            symbols++;
    }

    // Calculate password strength based on length and character types
    if (length < 8)
        strength = 1;
    else if (length < 12)
        strength = 2;
    else
        strength = 3;

    if (upper < 1 || lower < 1 || digits < 1 || symbols < 1)
        strength--;

    // Output password strength
    printf("Password Strength: ");

    switch (strength)
    {
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    return 0;
}