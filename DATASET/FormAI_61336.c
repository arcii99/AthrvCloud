//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: lively
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
   char password[50];
   int len, upper, lower, digits, special;

   printf("Please Enter Your Password: ");
   scanf("%s", password);

   len = strlen(password);
   upper = 0;
   lower = 0;
   digits = 0;
   special = 0;

   for (int i = 0; i < len; i++) {
      if (isupper(password[i])) {
         upper++;
      } else if (islower(password[i])) {
         lower++;
      } else if (isdigit(password[i])) {
         digits++;
      } else {
         special++;
      }
   }

   printf("\nPassword Strength Checker Results:\n");

   if (len < 8) {
      printf("Your password is weak, it should be atleast 8 characters.\n");
   } else if (upper == 0 || lower == 0 || digits == 0 || special == 0) {
      printf("Your password is moderate, it should contain atleast one uppercase letter, one lowercase letter, one digit, and one special character.\n");
   } else {
      printf("Your password is strong, Congratulations!\n");
   }

   return 0;
}