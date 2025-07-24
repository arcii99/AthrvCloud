//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char password[30];
   int length = 0, upperCase = 0, lowerCase = 0, digits = 0, symbols = 0;
   printf("Enter password: ");
   fgets(password, 30, stdin);
   password[strcspn(password, "\n")] = 0;
   length = strlen(password);

   for(int i = 0; i < length; i++) {
      if(password[i] >= 'A' && password[i] <= 'Z') {
         upperCase++;
      }
      else if(password[i] >= 'a' && password[i] <= 'z') {
         lowerCase++;
      }
      else if(password[i] >= '0' && password[i] <= '9') {
         digits++;
      }
      else {
         symbols++;
      }
   }

   printf("\nPassword Statistics\n");
   printf("====================\n");
   printf("Password Length: %d\n", length);
   printf("Uppercase Characters: %d\n", upperCase);
   printf("Lowercase Characters: %d\n", lowerCase);
   printf("Digit Characters: %d\n", digits);
   printf("Symbol Characters: %d\n", symbols);

   // Password strength calculation
   int strength = 0;
   if(length >= 8) {
      strength++;
   }
   if(upperCase > 0 && lowerCase > 0) {
      strength++;
   }
   if(digits > 0) {
      strength++;
   }
   if(symbols > 0) {
      strength++;
   }

   printf("\nPassword Strength: ");
   switch(strength) {
      case 0:
         printf("Very Weak\n");
         break;
      case 1:
         printf("Weak\n");
         break;
      case 2:
         printf("Moderate\n");
         break;
      case 3:
         printf("Strong\n");
         break;
      case 4:
         printf("Very Strong\n");
         break;
      default:
         printf("N/A\n");
   }

   return 0;
}