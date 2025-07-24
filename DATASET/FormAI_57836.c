//FormAI DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countWords(char *input) {
   char *pos = input;
   int count = 0;

   while (*pos != '\0') {
      while (*pos == ' ' || *pos == '\t' || *pos == '\n')
         *pos++ = '\0';
      if (*pos != '\0' && (*(pos - 1) == '\0' || count == 0))
         count++;
      pos++;
   }

   printf("The number of words in the given input is : %d.\n", count);
}

int main() {
   char inputString[500];

   printf("Enter your input string (Maximum 500 characters) : ");
   fgets(inputString, sizeof(inputString), stdin);

   countWords(inputString);

   return 0;
}