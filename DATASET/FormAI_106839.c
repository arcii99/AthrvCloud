//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Surrealist Password Strength Checker!\n");
    
    printf("Please enter your password: ");
    char password[256];
    fgets(password, 256, stdin);
    password[strcspn(password, "\n")] = 0;

    int length = strlen(password);
    printf("Your password is %d characters long.\n", length);

    int upper = 0, lower = 0, digit = 0, special = 0;
    for(int i = 0; i < length; i++)
    {
        char c = password[i];
        if(isupper(c))
        {
            upper++;
        }
        else if(islower(c))
        {
            lower++;
        }
        else if(isdigit(c))
        {
            digit++;
        }
        else
        {
            special++;
        }
    }

    printf("Your password contains:\n");
    printf("  - %d uppercase letters\n", upper);
    printf("  - %d lowercase letters\n", lower);
    printf("  - %d digits\n", digit);
    printf("  - %d special characters\n", special);

    int strength = 0;
    if(length < 8)
    {
        printf("Your password is too short!\n");
        return 0;
    }
    else if(length >= 8 && length < 12)
    {
        strength += 1;
    }
    else if(length >= 12 && length < 16)
    {
        strength += 2;
    }
    else if(length >= 16 && length < 20)
    {
        strength += 3;
    }
    else if(length >= 20)
    {
        strength += 4;
    }

    if(upper == 0)
    {
        printf("Your password needs at least one uppercase letter!\n");
        return 0;
    }
    else if(upper == 1)
    {
        strength += 1;
    }
    else if(upper > 1)
    {
        strength += 2;
    }

    if(lower == 0)
    {
        printf("Your password needs at least one lowercase letter!\n");
        return 0;
    }
    else if(lower == 1)
    {
        strength += 1;
    }
    else if(lower > 1)
    {
        strength += 2;
    }

    if(digit == 0)
    {
        printf("Your password needs at least one digit!\n");
        return 0;
    }
    else if(digit == 1)
    {
        strength += 1;
    }
    else if(digit > 1)
    {
        strength += 2;
    }

    if(special == 0)
    {
        printf("Your password needs at least one special character!\n");
        return 0;
    }
    else if(special == 1)
    {
        strength += 1;
    }
    else if(special > 1)
    {
        strength += 2;
    }

    printf("Your password has a strength score of %d out of 10.\n", strength);

    printf("Thank you for using the Surrealist Password Strength Checker!\n");

    return 0;
}