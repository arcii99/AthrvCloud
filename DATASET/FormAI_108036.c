//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: lively
#include <stdio.h>

int main() {
   char phrase[] = "Meow meow meow!"; // Input phrase to be translated
   printf("Input phrase: %s\n", phrase);
   int i = 0;
   while (phrase[i]) { // Loop through the phrase to translate
      switch (phrase[i]) { // Translate each character
         case 'M':
            printf("C Cat says 'Meow'! ");
            break;
         case 'e':
            printf("C Cat says 'Eow'! ");
            break;
         case 'o':
            printf("C Cat says 'Ow'! ");
            break;
         case 'w':
            printf("C Cat says 'W'! ");
            break;
         case ' ':
            printf("C Cat says 'Purr'! ");
            break;
         case '!':
            printf("C Cat says 'Mrrrow'! ");
            break;
         default:
            printf("C Cat doesn't know what to say! ");
      }
      i++;
   }
   return 0;
}