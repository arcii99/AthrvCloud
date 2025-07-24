//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
   char password[100];
   int length, hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;

   printf("Enter a password: ");
   scanf("%s", password);

   length = strlen(password);

   for (int i = 0; i < length; i++) {
      if (password[i] >= 'a' && password[i] <= 'z') {
         hasLower = 1;
      } else if (password[i] >= 'A' && password[i] <= 'Z') {
         hasUpper = 1;
      } else if (password[i] >= '0' && password[i] <= '9') {
         hasDigit = 1;
      } else {
         hasSpecial = 1;
      }
   }

   if (length < 8 || !hasLower || !hasUpper || !hasDigit || !hasSpecial) {
      printf("Password is not strong enough.\n");
      if (length < 8) {
         printf("Password should be at least 8 characters long.\n");
      }
      if (!hasLower) {
         printf("Password should have at least one lowercase letter.\n");
      }
      if (!hasUpper) {
         printf("Password should have at least one uppercase letter.\n");
      }
      if (!hasDigit) {
         printf("Password should have at least one digit.\n");
      }
      if (!hasSpecial) {
         printf("Password should have at least one special character.\n");
      }
   } else {
      printf("Password is strong enough.\n");
   }

   return 0;
}