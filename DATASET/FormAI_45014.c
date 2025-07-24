//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[20];
    int length, i;
    int upper_case = 0, lower_case = 0, digit = 0, special_char = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8 || length > 12)
    {
        printf("Your password must be between 8 and 12 characters long.\n");
        exit(0);
    }

    for (i = 0; i < length; i++)
    {
        if (isupper(password[i]))
            upper_case++;

        if (islower(password[i]))
            lower_case++;

        if (isdigit(password[i]))
            digit++;

        if (password[i] == '$' || password[i] == '#' || password[i] == '@')
            special_char++;
    }

    if (upper_case == 0 || lower_case == 0 || digit == 0 || special_char == 0)
    {
        printf("Your password is weak and must contain at least one uppercase letter, one lowercase letter, one digit and one special character ($, # or @).\n");
        exit(0);
    }

    printf("Congratulations! Your password is strong and meets the criteria.\n");

    return 0;
}