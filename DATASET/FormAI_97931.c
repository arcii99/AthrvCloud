//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
   char alienLanguage[] = "ztksnethawlkyvjrdcufpq";

   printf("Welcome to the Alien Language Translator!\n");
   printf("Please input the word you would like to translate: ");

   char input[100];
   scanf("%s", input);

   int length = strlen(input);
   printf("Translation: ");
   for(int i=0; i<length; i++) {
      char currentChar = input[i];
      int translationIndex = -1;
      
      for(int j=0; j<26; j++) {
         if(currentChar == alienLanguage[j]) {
            translationIndex = j;
            break;
         }
      }

      if(translationIndex == -1) {
         printf("%c", currentChar);
      } else {
         char translatedChar = 'a' + translationIndex;
         printf("%c", translatedChar);
      }
   }
   printf("\n");

   return 0;
}