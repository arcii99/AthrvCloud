//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: realistic
#include <stdio.h>
#include <string.h>

int main()
{
   char c_cat_word[100], c_translated_word[100];
   int i, j, length;

   // mapping of C Cat words
   char c_cat_words[11][10] = {"Meow", "Purr", "Scratch", "Hiss", "Nap", "Fish", "Mouse", "Kitten", "Tuna", "Whiskers", "Fur"};
   // mapping of English words
   char translated_words[11][15] = {"Hello", "Love", "Itch", "Angry", "Sleep", "Food", "Hunt", "Baby Cat", "Fish Food", "Hair", "Coat"};

   printf("Welcome to C Cat Language Translator!\n\n");

   printf("Please enter a C Cat word to translate: ");
   scanf("%s", c_cat_word);
   
   length = strlen(c_cat_word);

   // loop through the C Cat word and find the matching word
   for(i=0; i<length; i++) {
      for(j=0; j<11; j++) {
         if(c_cat_word[i] == c_cat_words[j][i]) {
            c_translated_word[i] = translated_words[j][i];
         }
      }
   }

   // output the translated word
   printf("\nTranslated word: %s", c_translated_word);

   return 0;
}