//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char password[50];
    int length,i;
    int upper=0,lower=0,number=0,special=0;
    printf("My dearest, please enter your password: ");
    scanf("%s",password);
    length=strlen(password);
    
    for(i=0;i<length;i++)
    {
        if(password[i]>='A' && password[i]<='Z')
        {
            upper++;
        }
        else if(password[i]>='a' && password[i]<='z')
        {
            lower++;
        }
        else if(password[i]>='0' && password[i]<='9')
        {
            number++;
        }
        else
        {
            special++;
        }
    }
    
    printf("\nMy love, here is an evaluation of your password:\n");
    printf("--------------------------------------------------\n");
    printf("|Criteria         |  Status   |    Count           |\n");
    printf("|-----------------------------------------------|\n");
    printf("|Password Length  |          |     %d               |\n",length);
    
    if(upper>0)
    {
        printf("|Uppercase Letter |  Valid   |     %d               |\n",upper);
    }
    else
    {
        printf("|Uppercase Letter | Invalid! |    None             |\n");
    }
    
    if(lower>0)
    {
        printf("|Lowercase Letter |  Valid   |     %d               |\n",lower);
    }
    else
    {
        printf("|Lowercase Letter | Invalid! |    None             |\n");
    }
    
    if(number>0)
    {
        printf("|Numeric Digit    |  Valid   |     %d               |\n",number);
    }
    else
    {
        printf("| Numeric Digit   | Invalid! |    None             |\n");
    }
    
    if(special>0)
    {
        printf("|Special Character|  Valid   |     %d               |\n",special);
    }
    else
    {
        printf("|Special Character| Invalid! |    None              |\n");
    }
    
    printf("|-----------------------------------------------|\n");
    
    if(length>=8 && upper>0 && lower>0 && number>0 && special>0)
    {
        printf("\nMy love, congratulations! Your password is STRONG and VALID!\n");
    }
    else if(length<8)
    {
        printf("\nMy love, your password length is TOO SHORT. Please try again.\n");
    }
    else
    {
        printf("\nMy love, your password is WEAK and INVALID. Please try again.\n");
    }
    
    return 0;
}