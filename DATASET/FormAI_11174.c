//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>

int countWords(char str[]) {
   int count = 0, i;

   for (i = 0; str[i] != '\0'; i++) {
      if (str[i] == ' ') {
         count++;
      }
   }

   // Add one to count to include the last word in the string
   return count + 1;
}

int main() {
   char str[] = "This is a sample C string";
   int wordCount = countWords(str);

   printf("Number of words in string: %d", wordCount);

   return 0;
}