//FormAI DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
   char str[100];
   int i, wordCount=0;
   printf("Enter a string: ");
   gets(str);

   for (i = 0; i<strlen(str); i++) {
      if (str[i] == ' ' && str[i+1] != ' ') {
         wordCount++;
      }
   }

   printf("Total number of words in the string: %d", wordCount+1);

   return 0;
}