//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[50];
    int length, hasUpperCase = 0, hasLowerCase = 0, hasDigit = 0, hasSpecialChar = 0, i;

    printf("Enter the password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            hasUpperCase = 1;

        if (password[i] >= 'a' && password[i] <= 'z')
            hasLowerCase = 1;

        if (password[i] >= '0' && password[i] <= '9')
            hasDigit = 1;

        if (!(password[i] >= 'A' && password[i] <= 'Z') &&
            !(password[i] >= 'a' && password[i] <= 'z') &&
            !(password[i] >= '0' && password[i] <= '9'))
            hasSpecialChar = 1;
    }

    printf("\nPassword Strength: ");

    if (length < 6 || length > 20)
        printf("Poor - Length should be between 6 and 20\n");
    else if (hasUpperCase == 0 || hasLowerCase == 0 || hasDigit == 0 || hasSpecialChar == 0)
        printf("Weak - Password should contain at least one uppercase,lowercase character, digit and special character\n");
    else
        printf("Strong. Congrats, your password is a survivor!\n");

    return 0;
}