//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
   char sentence[100];
   int i;
   int j;

   printf("Please input a sentence in C Cat Language: ");
   fgets(sentence, sizeof(sentence), stdin);  // read in user input
   sentence[strcspn(sentence, "\n")] = '\0'; // remove newline character from input

   for(i = 0; sentence[i] != '\0'; i++) { // loop through every character in input
      if(sentence[i] == 'm') {
         printf("meow"); // translate "m" to "meow"
      } else if(sentence[i] == 'p') {
         printf("purr"); // translate "p" to "purr"
      } else if(sentence[i] == 'h') {
         printf("hiss"); // translate "h" to "hiss"
      } else if(sentence[i] == 'c') {
         printf("cat"); // translate "c" to "cat"
      } else if(sentence[i] == 't') {
         printf("tail"); // translate "t" to "tail"
      } else if(sentence[i] == 'n') {
         printf("nip"); // translate "n" to "nip"
      } else if(sentence[i] == 's') {
         printf("scratch"); // translate "s" to "scratch"
      } else {
         printf("%c", sentence[i]); // if character is not recognized, print as is
      }
   }

   printf("\n");

   return 0;
}