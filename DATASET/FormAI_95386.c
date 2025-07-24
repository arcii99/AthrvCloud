//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char password[50];
   int upper = 0, lower = 0, digit = 0, special = 0, length = 0;
   
   printf("Enter password: ");
   scanf("%s", password);
   
   length = strlen(password);
   
   if (length >= 8 && length <= 12) {
      for (int i = 0; i < length; i++) {
         if (isupper(password[i])) {
            upper++; 
         }
         if (islower(password[i])) {
            lower++;
         }
         if (isdigit(password[i])) {
            digit++;
         }
         if (!isdigit(password[i]) && !isalpha(password[i])) {
            special++;
         }
      }
   
      if (upper >= 1 && lower >= 1 && digit >= 1 && special >= 1) {
         printf("Password strength: STRONG");
      } else if ((upper >= 1 || lower >= 1) && digit >= 1 && special >= 1) {
         printf("Password strength: MEDIUM");
      } else {
         printf("Password strength: WEAK");
      }
   } else {
      printf("Password must be 8-12 characters long.");
   }
   
   return 0;
}