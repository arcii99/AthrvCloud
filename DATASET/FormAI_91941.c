//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>

int main() {
   char string[1000];
   int characters = 0, words = 0, lines = 0;

   printf("Enter a paragraph or sentence:\n");
   fgets(string,1000,stdin);

   for(int i=0; string[i]!='\0'; i++) {
      characters++;

      if(string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
         words++;
      }

      if(string[i] == '\n') {
         lines++;
      }
   }

   printf("\nStatistics:\n");
   printf("Characters (with spaces and punctuation): %d\n", characters);
   printf("Words: %d\n", words+1);
   printf("Lines: %d\n", lines+1);
   
   printf("\nWow! you entered %d characters, %d words and %d lines!", characters, words+1, lines+1);

   return 0;
}