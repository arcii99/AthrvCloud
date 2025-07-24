//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char password[100];
    int length, lowerCaseCount = 0, upperCaseCount = 0, digitCount = 0, specialCharCount = 0;
    
    printf("Enter a password:\n");
    scanf("%s", password);
    
    length = strlen(password);
    
    for(int i=0; i<length; i++)
    {
        if('a'<=password[i] && password[i]<='z')
        {
            lowerCaseCount++;
        } 
        else if('A'<=password[i] && password[i]<='Z')
        {
            upperCaseCount++;
        }
        else if('0'<=password[i] && password[i]<='9')
        {
            digitCount++;
        }
        else
        {
            specialCharCount++;
        }
    }
    
    if(length>=10 && length<=20 && lowerCaseCount>=3 && upperCaseCount>=2 && digitCount>=2 && specialCharCount>=1)
    {
        printf("The password is strong. Good job!\n");
    }
    else if(length<8)
    {
        printf("The password is too short. It should be at least 8 characters long.\n");
    }
    else
    {
        printf("The password is weak. It should be between 10 and 20 characters long and should contain at least 3 lowercase letters, 2 uppercase letters, 2 digits, and 1 special character.\n");
    }
    
    return 0;
}