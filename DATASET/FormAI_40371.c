//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_words(char *input_str);

int main() {
   char input_str[1000];
   printf("Enter a string: ");
   fgets(input_str, 1000, stdin);
   printf("Word count is %d\n", count_words(input_str));
   return 0;
}

int count_words(char *input_str) {
   int count = 0;
   int in_word = 0;
   while (*input_str) {
      if (isalnum(*input_str) && !in_word) {
         in_word = 1;
         count++;
      }
      else if (!isalnum(*input_str)) {
         in_word = 0;
      }
      input_str++;
   }
   return count;
}