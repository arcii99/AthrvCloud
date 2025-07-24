//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
/* This function checks if the password is strong enough */
int isPasswordStrong(char* password)
{
    int len = strlen(password);
 
    int hasLower = 0, hasUpper = 0;
    int hasDigit = 0, specialChar = 0;
    for (int i = 0; i < len; i++)
    {
        if (password[i]>='a' && password[i]<='z')
            hasLower = 1;
        else if (password[i]>='A' && password[i]<='Z')
            hasUpper = 1;
        else if (password[i]>='0' && password[i]<='9')
            hasDigit = 1;
        else
            specialChar=1;
    }

    if (hasLower && hasUpper && hasDigit && specialChar && (len >= 8))
        return 1;
 
    return 0;
}
 
int main()
{
    char password[100];
    printf("Enter a password:\n");
    scanf("%s", password);
 
    if (isPasswordStrong(password))
        printf("The password is strong");
    else
        printf("The password is NOT strong");
 
    return 0;
}