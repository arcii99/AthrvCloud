//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
   char input[100];
   printf("Enter the text to translate into Alien Language: ");
   scanf("%s", input);
   
   // The Alien Language replaces vowels with "i" and consonants with "o"
   for (int i = 0; i < strlen(input); i++) {
      char c = input[i];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
         input[i] = 'i';
      } else {
         input[i] = 'o';
      }
   }
   
   printf("The text in Alien Language is: %s", input);
   
   return 0;
}