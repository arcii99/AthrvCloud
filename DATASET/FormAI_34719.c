//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
   char password[100];
   int i, length, upperCase, lowerCase, digit, specialChar, strong;
 
   printf("Enter password:\n");
   scanf("%s", password);
 
   length = strlen(password);
   upperCase = lowerCase = digit = specialChar = strong = 0;
 
   if (length >= 8 && length <= 20)
   {
      for (i = 0; i < length; i++)
      {
         if (password[i] >= 'A' && password[i] <= 'Z')
            upperCase++;
         else if (password[i] >= 'a' && password[i] <= 'z')
            lowerCase++;
         else if (password[i] >= '0' && password[i] <= '9')
            digit++;
         else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&')
            specialChar++;
      }
 
      if ((upperCase >= 1) && (lowerCase >= 1) && (digit >= 1) && (specialChar >= 1))
         strong = 1;
 
      if (strong)
         printf("The password is strong.\n");
      else
         printf("The password is weak.\n");
   }
   else
      printf("The password should be between 8 and 20 characters long.\n");
 
   return 0;
}