//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[50];
    int len, i, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecialChar = 0;

    printf("Enter password: ");
    fgets(password, 50, stdin);

    len = strlen(password) - 1;

    for(i=0; i<len; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            hasUpper = 1;
        else if(password[i] >= 'a' && password[i] <= 'z')
            hasLower = 1;
        else if(password[i] >= '0' && password[i] <= '9')
            hasDigit = 1;
        else
            hasSpecialChar = 1;
    }

    printf("\nPassword strength:\n");

    if(len < 8 || !hasUpper || !hasLower || !hasDigit || !hasSpecialChar)
    {
        printf("- Weak\n");
        printf("Password must be at least 8 characters long and must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }
    else
    {
        printf("- Strong\n");
        printf("Password meets the requirements.\n");
    }

    return 0;
}