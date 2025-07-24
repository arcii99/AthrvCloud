//FormAI DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <string.h>

int countWords(char *str) {

   int i, count = 0;
   int len = strlen(str);

   for (i = 0; i < len; i++) {
      if (str[i] == ' ') {
         count++;
      }
   }

   return count + 1; 
}

int main() {

   char str[100];
   printf("Enter a sentence: ");
   gets(str);

   int count = countWords(str);
   printf("Total words: %d", count);

   return 0;
}