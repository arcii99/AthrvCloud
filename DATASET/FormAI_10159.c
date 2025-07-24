//FormAI DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <ctype.h>

int main() {
   char input[1000];
   int words = 0;

   printf("Enter a sentence: ");
   fgets(input, sizeof(input), stdin);

   for (int i = 0; input[i] != '\0'; i++) {
      if ((i == 0 && isalpha(input[i])) || (isspace(input[i - 1]) && isalpha(input[i]))) {
         words++;
      }
   }

   printf("Word count: %d\n", words);
   
   return 0;
}