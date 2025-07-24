//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>

int main() {
   char password[30]; //assumes max password length is 30 characters
   int i, length, uppercase, lowercase, numbers, special_char;

   length = uppercase = lowercase = numbers = special_char = 0;

   printf("Enter a password: ");
   scanf("%s", password);

   length = strlen(password);

   //check each character in the password and increment corresponding counter
   for(i=0; i<length; i++) {
      if(password[i] >= 'A' && password[i] <= 'Z') { 
         uppercase++;
      }
      else if(password[i] >= 'a' && password[i] <= 'z') { 
         lowercase++;
      }
      else if(password[i] >= '0' && password[i] <= '9') { 
         numbers++;
      }
      else {
         special_char++;
      }
   }

   //password strength criteria
   if(length >= 8 && lowercase > 0 && uppercase > 0 && numbers > 0 && special_char > 0) {
      printf("\nStrong password!\n");
   }
   else if(length >= 6 && lowercase > 0 && uppercase > 0 && numbers > 0 && special_char == 0) {
      printf("\nModerate password\n");
   }
   else {
      printf("\nWeak password!\n");
   }

   return 0;
}