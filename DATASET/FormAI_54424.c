//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: medieval
#include<stdio.h>
#include<string.h>

int main() {
   char password[50];
   int passwordLength, i, numbersCount = 0, specialCount = 0, capCount = 0, smallCount = 0;

   printf("Enter your password: ");
   scanf("%s", password);

   passwordLength = strlen(password);

   if (passwordLength < 8) {
      printf("Your password is too weak!\nIt must contain at least 8 characters.\n");
   }
   else {
      for (i = 0; i < passwordLength; i++) {
         if (password[i] >= '0' && password[i] <= '9') {
            numbersCount++;
         }
         else if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z')) {
            if (password[i] >= 'a' && password[i] <= 'z') {
               smallCount++;
            }
            else {
               capCount++;
            }
         }
         else {
            specialCount++;
         }
      }

      if (numbersCount == 0 || specialCount == 0 || capCount == 0 || smallCount == 0) {
         printf("Your password is weak!\nIt must contain at least one:\n1. Upper case letter\n2. Lower case letter\n3. Special character\n4. Number [0-9]\n");
      }
      else {
         printf("Welcome to the Medieval World!");
      }
   }
   return 0;
}