//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
   char input[100];
   int counts[26] = {0};

   printf("Enter a sentence: ");
   fgets(input, 100, stdin);
   input[strcspn(input, "\n")] = 0;

   for (int i = 0; i < strlen(input); i++) {
      if (isalpha(input[i])) {
         counts[toupper(input[i]) - 'A']++;
      }
   }

   printf("Word Frequency:\n");
   for (int i = 0; i < 26; i++) {
      printf("%c: %d\n", 'A' + i, counts[i]);
   }

   printf("Thank you for using our futuristic C Word Frequency Counter!\n");
   return 0;
}