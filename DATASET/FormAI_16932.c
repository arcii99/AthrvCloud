//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
   char password[30];
   int length, i;
   int upper = 0, lower = 0, digit = 0, special = 0;

   printf("Enter your password: ");
   scanf("%s", password);

   length = strlen(password);

   //Counting the number of uppercase, lowercase, digits and special characters in the password
   for(i = 0; i < length; i++)
   {
     if(isupper(password[i])) //Checking for uppercase letter
       upper++;
     else if(islower(password[i])) //Checking for lowercase letter
       lower++;
     else if(isdigit(password[i])) //Checking for digit
       digit++;
     else //Checking for special characters
       special++;
   }

   //Checking the strength of the password
   if(length >= 8 && upper > 0 && lower > 0 && digit > 0 && special > 0)
     printf("Password Strength: Strong");
   else if(length >= 8 && upper > 0 && lower > 0 && digit > 0 && special == 0)
     printf("Password Strength: Medium");
   else if(length >= 8 && upper > 0 && lower > 0 && digit == 0 && special == 0)
     printf("Password Strength: Weak");
   else
     printf("Password Strength: Very Weak");

   return 0;
}