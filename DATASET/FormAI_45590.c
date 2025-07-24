//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[40];
    int length, i, upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);

    length = strlen(password) - 1;

    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
            upper++;
        else if (islower(password[i]))
            lower++;
        else if (isdigit(password[i]))
            digit++;
        else
            special++;
    }

    if (length >= 8 && upper > 0 && lower > 0 && digit > 0 && special > 0)
        printf("The password is strong.\n");
    else if (length < 8 && upper == 0 && lower == 0 && digit == 0 && special == 0)
        printf("The password is very weak.\n");
    else
        printf("The password is weak.\n");

    return 0;
}