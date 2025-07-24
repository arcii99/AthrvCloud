//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: careful
#include<stdio.h>
#include<string.h>

int main()
{
    char password[20];
    int len, i, upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter a password: ");
    fgets(password, 20, stdin);

    len = strlen(password) - 1;

    for(i = 0; i < len; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z')
            upper++;

        if(password[i] >= 'a' && password[i] <= 'z')
            lower++;

        if(password[i] >= '0' && password[i] <= '9')
            digit++;

        if(password[i] >= 33 && password[i] <= 47 || password[i] >= 58 && password[i] <= 64 || password[i] >= 91 && password[i] <= 96 || password[i] >= 123 && password[i] <= 126)
            special++;
    }

    if(len >= 8 && len <=16 && upper > 0 && lower > 0 && digit > 0 && special > 0)
        printf("Password is Strong");

    else if ((len >= 8 && len <=16) && ((upper > 0 && lower > 0 && digit > 0) || (upper > 0 && lower > 0 && special > 0) || (upper > 0 && digit > 0 && special > 0) || (lower > 0 && digit > 0 && special > 0)))
        printf("Password is Moderate");

    else
        printf("Password is Weak");
    
    return 0;
}