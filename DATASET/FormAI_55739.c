//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: retro
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char password[50];
    int length, i, upper=0, lower=0, digit=0, symbol=0;
    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);
    if(length < 8)
    {
        printf("Password is weak! It is too short.\n");
        return 0;
    }
    for(i=0;i<length;i++)
    {
        if(isupper(password[i]))
            upper++;
        else if(islower(password[i]))
            lower++;
        else if(isdigit(password[i]))
            digit++;
        else
            symbol++;
    }
    if(upper > 0 && lower > 0 && digit > 0 && symbol > 0)
        printf("Password is strong! Well done.\n");
    else
        printf("Password is weak! Try again.\n");
    return 0;
}