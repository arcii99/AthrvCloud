//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char password[20], ch;
    int i, length, lower = 0, upper = 0, digit = 0, special = 0;

    printf("Enter a password: ");
    fgets(password, 20, stdin);

    length = strlen(password);

    for(i = 0; i < length; i++)
    {
        ch = password[i];

        if(islower(ch))
        {
            lower++;
        }
        else if(isupper(ch))
        {
            upper++;
        }
        else if(isdigit(ch))
        {
            digit++;
        }
        else
        {
            special++;
        }
    }

    if(lower >= 1 && upper >= 1 && digit >= 1 && special >=1 && length >= 8 && length <= 20)
    {
        printf("Strong Password");
    }
    else if(length > 20)
    {
        printf("Password is too long");
    }
    else if(length < 8)
    {
        printf("Password is too short");
    }
    else
    {
        printf("Password is weak");
    }
    return 0;
}