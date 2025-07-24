//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 8

int main()
{
    char password[PASSWORD_LENGTH + 1];
    int length = 0, uppercase = 0, lowercase = 0, digit = 0, special = 0;

    printf("Enter your password: ");
    fgets(password, PASSWORD_LENGTH + 1, stdin);
    length = strlen(password);

    for (int i = 0; i < length - 1; i++)
    {
        if (isupper(password[i]))
            uppercase++;
        else if (islower(password[i]))
            lowercase++;
        else if (isdigit(password[i]))
            digit++;
        else if (ispunct(password[i]))
            special++;
    }

    if (length < PASSWORD_LENGTH)
        printf("Password must be at least %d characters\n", PASSWORD_LENGTH);
    else if (uppercase < 1 || lowercase < 1 || digit < 1 || special < 1)
        printf("Password must contain uppercase letters, lowercase letters, digits, and special characters\n");
    else
        printf("Password is strong\n");

    return 0;
}