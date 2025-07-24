//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
   char alien_word[50];
   char english_word[50];
   printf("Enter an alien word: ");
   scanf("%s", alien_word);
   
   if(strcmp(alien_word, "Galaxxon") == 0) {
      strcpy(english_word, "Hello");
   }
   else if(strcmp(alien_word, "Zorbon") == 0) {
      strcpy(english_word, "Goodbye");
   }
   else if(strcmp(alien_word, "Gorgon") == 0) {
      strcpy(english_word, "Yes");
   }
   else if(strcmp(alien_word, "Xandar") == 0) {
      strcpy(english_word, "No");
   }
   else {
      printf("Sorry, I don't know that word!");
      return 0;
   }
   
   printf("The translation of %s is %s", alien_word, english_word);
   return 0;
}