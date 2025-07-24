//FormAI DATASET v1.0 Category: Text processing ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct word_freq {
   char word[50];
   int count;
} word_freq_t;

int main() {
   FILE *fp;
   char c, word[50];
   int i, j, word_len, num_words = 0;
   word_freq_t word_freq[1000];

   fp = fopen("input.txt", "r");
   if (fp == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   while ((c = fgetc(fp)) != EOF) {
      if (isalpha(c)) {
         word_len = strlen(word);
         word[word_len] = tolower(c);
         word[word_len + 1] = '\0';
      } else if (word_len > 0) {
         for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
               memmove(&word[i], &word[i+1], strlen(word)-i);
               i--;
               word_len--;
            }
         }
         for (i = 0; i < num_words; i++) {
            if (strcmp(word, word_freq[i].word) == 0) {
               word_freq[i].count++;
               break;
            }
         }
         if (i == num_words) {
            strcpy(word_freq[num_words].word, word);
            word_freq[num_words].count = 1;
            num_words++;
         }
         word[0] = '\0';
         word_len = 0;
      }
   }

   fclose(fp);

   for (i = 0; i < num_words; i++) {
      printf("%s - %d\n", word_freq[i].word, word_freq[i].count);
   }

   return 0;
}