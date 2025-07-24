//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
   char sentence[1000];
   printf("Enter a sentence: ");
   fgets(sentence, sizeof(sentence), stdin);

   // Replace all vowels with 'peace'
   for (int i = 0; i < strlen(sentence); i++) {
      if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i'
         || sentence[i] == 'o' || sentence[i] == 'u') {
         sentence[i] = 'p';
         sentence[i+1] = 'e';
         sentence[i+2] = 'a';
         sentence[i+3] = 'c';
         sentence[i+4] = 'e';
         i += 4;
      }
   }

   printf("\nYour peaceful sentence: %s", sentence);
   return 0;
}