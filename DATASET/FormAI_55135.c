//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// function to check if the password is strong
bool isPasswordStrong(char password[])
{
    int len = strlen(password);
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSymbol = false;
    
    // if password length is less than 8
    if (len < 8)
    {
        printf("Password must contain at least 8 characters\n");
        return false;
    }
    
    // checking if password has atleast one uppercase letter, one lowercase letter, one digit and one special character
    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
        {
            hasUpperCase = true;
        }
        else if (islower(password[i]))
        {
            hasLowerCase = true;
        }
        else if (isdigit(password[i]))
        {
            hasDigit = true;
        }
        else if (ispunct(password[i]) || isspace(password[i]))
        {
            hasSymbol = true;
        }
    }

    if (!(hasUpperCase && hasLowerCase && hasDigit && hasSymbol))
    {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit and one special character\n");
        return false;
    }
    
    // if password satisfies all conditions
    return true;
}

int main()
{
    char password[100];
    printf("Enter password: ");
    fgets(password, 100, stdin);
    password[strcspn(password, "\n")] = 0;
    
    // check if password is strong or not
    if (isPasswordStrong(password))
    {
        printf("Congratulations! Your password is strong");
    }
    else
    {
        printf("Please choose a stronger password");
    }
    
    return 0;
}