//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: authentic
#include <stdio.h>
#include <string.h>

int main()
{
    char password[50];
    int length, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter password: ");
    fgets(password, 50, stdin);

    length = strlen(password) - 1;

    for (int i = 0; i < length; i++) 
    {
        if (password[i] >= 'A' && password[i] <= 'Z') 
        {
            hasUpper = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') 
        {
            hasLower = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9') 
        {
            hasDigit = 1;
        }
        else 
        {
            hasSpecial = 1;
        }
    }

    printf("Password Strength: ");

    if (length < 8) 
    {
        printf("Weak. Password should be at least 8 characters long.\n");
    }
    else if (hasUpper == 0 || hasLower == 0 || hasDigit == 0 || hasSpecial == 0) 
    {
        printf("Moderate. Password should contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
    }
    else 
    {
        printf("Strong. Password meets all requirements.\n");
    }

    return 0;
}