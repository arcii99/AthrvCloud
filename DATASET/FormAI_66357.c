//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
   char inputStr[100];
   int vowels = 0, consonants = 0, digits = 0, spaces = 0;

   printf("Enter a string: ");
   fgets(inputStr, 100, stdin);

   for(int i = 0; i < strlen(inputStr); i++) {
      if(inputStr[i] == ' ') {
         spaces++;
      } else if(inputStr[i] >= '0' && inputStr[i] <= '9') {
         digits++;
      } else if(inputStr[i] >= 'A' && inputStr[i] <= 'Z' || inputStr[i] >= 'a' && inputStr[i] <= 'z') {
         char character = tolower(inputStr[i]);

         if(character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
            vowels++;
         } else {
            consonants++;
         }
      }
   }

   printf("\nVowels: %d", vowels);
   printf("\nConsonants: %d", consonants);
   printf("\nDigits: %d", digits);
   printf("\nSpaces: %d", spaces);

   return 0;
}