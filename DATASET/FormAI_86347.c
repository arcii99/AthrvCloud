//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
   char alien_lang[26][10] = { "blip", "clu", "dop", "exi", "florp", "grill", "hup", "jawk", "klick", "lurp", "mick", "noyb", "plop", "quox", "rolf", "scree", "trax", "ufda", "vash", "wham", "xong", "yip", "zoop" };
   char english_lang[26][10] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
   char input[100];

   printf("Enter a sentence in alien language: ");
   fgets(input, 100, stdin);

   for (int i = 0; i < strlen(input); i++) {
       if (input[i] == ' ') {
           printf(" ");
       } else {
           for (int j = 0; j < 26; j++) {
               if (strncmp(&input[i], alien_lang[j], strlen(alien_lang[j])) == 0) {
                   printf("%s", english_lang[j]);
                   i += strlen(alien_lang[j])-1;
               }
           }
       }
   }

   return 0;
}