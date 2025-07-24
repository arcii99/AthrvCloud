//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 10

int main() {

   char password[PASSWORD_LENGTH];
   int i, j, k;
   int uppercaseCount = 0, lowercaseCount = 0, digitCount = 0, specialCount = 0;

   srand(time(NULL)); // seed random number generator

   // Generate random characters
   for(i=0; i < PASSWORD_LENGTH; i++) {
      int randNum = rand() % 4;

      switch(randNum) {
         case 0:
            password[i] = 'A' + rand() % 26; // uppercase
            uppercaseCount++;
            break;
         case 1:
            password[i] = 'a' + rand() % 26; // lowercase
            lowercaseCount++;
            break;
         case 2:
            password[i] = '0' + rand() % 10; // digit
            digitCount++;
            break;
         case 3:
            password[i] = '!' + rand() % 15; // special character
            specialCount++;
            break;
      }
   }

   // Make sure password meets requirements
   while(uppercaseCount < 2 || lowercaseCount < 2 || digitCount < 2 || specialCount < 2) {

      // Replace a random character with a new one
      int replaceNum = rand() % PASSWORD_LENGTH;

      switch(rand() % 4) {
         case 0:
            if(uppercaseCount < 2) {
               password[replaceNum] = 'A' + rand() % 26;
               uppercaseCount++;
            }
            break;
         case 1:
            if(lowercaseCount < 2) {
               password[replaceNum] = 'a' + rand() % 26;
               lowercaseCount++;
            }
            break;
         case 2:
            if(digitCount < 2) {
               password[replaceNum] = '0' + rand() % 10;
               digitCount++;
            }
            break;
         case 3:
            if(specialCount < 2) {
               password[replaceNum] = '!' + rand() % 15;
               specialCount++;
            }
            break;
      }
   }

   // Print password
   printf("Your secure password is: ");
   for(i=0; i < PASSWORD_LENGTH; i++) {
      printf("%c", password[i]);
   }

   return 0;
}