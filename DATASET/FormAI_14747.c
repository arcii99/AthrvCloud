//FormAI DATASET v1.0 Category: Word Count Tool ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
   char str[100];
   char *wordArray[100];
   int countArray[100];
   int i, j, k, count = 0, n;

   printf("Enter a sentence: ");
   fgets(str, 100, stdin);
   str[strlen(str) - 1] = '\0';

   for (i = 0; str[i] != '\0';) {
      k = i;
      while ((str[i] != ' ') && (str[i] != '\0')) {
         i++;
      }
      int wordLength = i - k;
      char *word = (char*) malloc(wordLength + 1);
      memcpy(word, &str[k], wordLength);
      word[wordLength] = '\0';
      for (j = 0; j < count; j++) {
         if (strcmp(word, wordArray[j]) == 0) {
            countArray[j]++;
            break;
         }
      }
      if (j == count) {
         wordArray[j] = word;
         countArray[j]++;
         count++;
      }
      i++;
   }

   printf("\nWord Count: %d\n", count);

   for (i = 0; i < count; i++) {
      printf("%s: %d\n", wordArray[i], countArray[i]);
   }

   return 0;
}