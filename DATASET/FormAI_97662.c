//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_password_strength(char* password)
{
   int i, len, upper_count = 0, lower_count = 0, num_count = 0, sym_count = 0;
   len = strlen(password);

   for(i=0;i<len;i++)
   {
      if(isupper(password[i]))
         upper_count++;
      else if(islower(password[i]))
         lower_count++;
      else if(isdigit(password[i]))
         num_count++;
      else
         sym_count++;
   }

   if(len >= 8 && upper_count > 0 && lower_count > 0 && num_count > 0 && sym_count > 0)
      return 1;

   return 0;
}

int main()
{
   char password[50];

   printf("Enter your password: ");
   scanf("%s", password);

   if(check_password_strength(password))
      printf("Your password is strong!\n");
   else
      printf("Your password is weak, please try again!\n");

   return 0;
}