//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
   char password[50];
   int length, alphabets = 0, digits = 0, special_characters = 0;

   printf("Enter a password: ");
   scanf("%s", password);

   length = strlen(password);

   if (length <= 6) {
       printf("Your password is weak, it should have atleast 6 characters.\n");
   }
   else {
       for (int i = 0; password[i] != '\0'; i++) {
           if (isalpha(password[i])) {
               alphabets++;
           }
           else if (isdigit(password[i])) {
               digits++;
           }
           else {
               special_characters++;
           }
       }

       if (alphabets == 0) {
           printf("Your password is weak, it should contain atleast one alphabet.\n");
       }
       else if (digits == 0) {
           printf("Your password is weak, it should contain atleast one digit.\n");
       }
       else if (special_characters == 0) {
           printf("Your password is weak, it should contain atleast one special character.\n");
       }
       else {
           printf("Your password is strong.\n");
       }
   }

   return 0;
}