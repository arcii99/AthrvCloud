//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int length, i;
    int hasUpperCase = 0, hasLowerCase = 0, hasNumber = 0, hasSpecialChar = 0;

    printf("Enter your password:\n");
    fgets(password,100,stdin);

    length = strlen(password)-1;

    if (length<8)
    {
        printf("Sorry, your password must be at least 8 characters long.\n");
        exit(1);
    }
    else
    {
        for(i=0; i<length; i++)
        {
            if(isupper(password[i]))
            {
                hasUpperCase = 1;
            }
            else if(islower(password[i]))
            {
                hasLowerCase = 1;
            }
            else if(isdigit(password[i]))
            {
                hasNumber = 1;
            }
            else
            {
                hasSpecialChar = 1;
            }
        }

        if(hasUpperCase && hasLowerCase && hasNumber && hasSpecialChar)
        {
            printf("Wow! Your password is strong as our love.\n");
        }
        else
        {
            printf("Sorry, your password is too weak for the strength of our love. Please include at least one uppercase letter, one lowercase letter, one number, and one special character.\n");
        }
    }

    return 0;
}