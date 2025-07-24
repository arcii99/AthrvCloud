//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char password[30];
    int len,i,flag=0,uppercase=0,lowercase=0,number=0,specialchar=0;
 
    printf("Enter a Password: ");
    fgets(password,30,stdin); //read input from user
 
    len=strlen(password)-1; //to eliminate newline
 
    if (len>=8)
    {
        for(i=0;i<len;i++)
        {
            if(isupper(password[i])) //checking uppercase alphabet
            {
                uppercase++;
            }
            else if(islower(password[i])) //checking lowercase alphabet
            {
                lowercase++;
            }
            else if(isdigit(password[i])) //checking numbers
            {
                number++;
            }
            else if(password[i]=='@'||password[i]=='#'||password[i]=='$') //checking special characters
            {
                specialchar++;
            }
        }
        if(uppercase>=1 && lowercase>=1 && number>=1 && specialchar>=1) //checking presence of all required elements
        {
            flag=1;
        }
    }
    //displaying output
    if(flag==1)
    {
        printf("Entered Password is Strong");
    }
    else
    {
        printf("Entered Password is Weak!\n");
        if(len<8)
        {
            printf("Password length should be at least 8.\n");
        }
        if(uppercase<1)
        {
            printf("Password should contain at least one uppercase letter.\n");
        }
        if(lowercase<1)
        {
            printf("Password should contain at least one lowercase letter.\n");
        }
        if(number<1)
        {
            printf("Password should contain at least one number.\n");
        }
        if(specialchar<1)
        {
            printf("Password should contain at least one special character [@,#,$].\n");
        }
    }

    return 0;
}