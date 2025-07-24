//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: safe
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    char password[20];
    int length, i, lowercase, uppercase, number, specialchar;
    lowercase = uppercase = number = specialchar = 0;

    printf("Enter Password: ");
    scanf("%s", password);
    length = strlen(password);

    /* Check for length */
    if(length < 8)
    {
        printf("Password is too short.\n");
        return 0;
    }

    /* Check for uppercase, lowercase, numbers, and special characters */
    for(i=0; i<length; i++)
    {
        if(islower(password[i]))
            lowercase++;
        else if(isupper(password[i]))
            uppercase++;
        else if(isdigit(password[i]))
            number++;
        else
            specialchar++;
    }

    /* Password strength criteria */
    if(lowercase > 0 && uppercase > 0 && number > 0 && specialchar > 0)
        printf("Your password is strong.\n");
    else if((lowercase == 0 && uppercase == 0) || (lowercase == 0 && number == 0) || (uppercase == 0 && number == 0) || (lowercase == 0 && specialchar == 0) || (uppercase == 0 && specialchar == 0) || (number == 0 && specialchar == 0))
        printf("Your password is weak. It must contain at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
    else
        printf("Your password is moderate. It can be more secure by containing at least one uppercase letter, one lowercase letter, one number, and one special character.\n");

    return 0;
}