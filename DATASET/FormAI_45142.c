//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main()
{
    char password[30];
    int len, i, uppercase = 0, lowercase = 0, digit = 0, otherchar = 0;

    printf("Enter the password: ");
    fgets(password, 30, stdin);
    len = strlen(password);

    for (i = 0; i < len; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
            uppercase++;
        else if (password[i] >= 'a' && password[i] <= 'z')
            lowercase++;
        else if (password[i] >= '0' && password[i] <= '9')
            digit++;
        else
            otherchar++;
    }

    printf("\nPassword Strength Meter: \n");

    if (len < 8)
    {
        printf("\nLength of password is less than 8 characters. ");
        printf("\nWeak Password\n");
    }

    else if (len >= 8 && len <= 12)
    {
        if (lowercase >= 1 && uppercase >= 1 && digit >= 1 && otherchar >= 1)
            printf("\nStrong Password\n");
        else if (lowercase >= 1 && uppercase >= 1 && digit >= 1 && otherchar == 0)
            printf("\nModerate Password\n");
        else
            printf("\nWeak Password\n");
    }

    else if (len > 12)
    {
        if (lowercase >= 1 && uppercase >= 1 && digit >= 1 && otherchar >= 1)
            printf("\nVery Strong Password\n");
        else if (lowercase >= 1 && uppercase >= 1 && digit >= 1 && otherchar == 0)
            printf("\nStrong Password\n");
        else
            printf("\nModerate Password\n");
    }

    return 0;
}