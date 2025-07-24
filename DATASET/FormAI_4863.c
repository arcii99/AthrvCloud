//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000
 
typedef struct {
   char word[MAX_WORD_LENGTH + 1];
   int count;
} word_entry;
 
word_entry words[MAX_WORDS];
int num_words = 0;
 
void add_word(const char* word) {
   int i;
   for (i = 0; i < num_words; i++) {
      if (strcmp(words[i].word, word) == 0) {
         words[i].count++;
         return;
      }
   }
   if (num_words == MAX_WORDS) {
      fprintf(stderr, "Too many words.\n");
      exit(1);
   }
   strcpy(words[num_words].word, word);
   words[num_words].count = 1;
   num_words++;
}
 
void sort_words() {
   int i, j;
   word_entry temp;
 
   for (i = 0; i < num_words; i++) {
      for (j = i + 1; j < num_words; j++) {
         if (strcmp(words[i].word, words[j].word) > 0) {
            temp = words[i];
            words[i] = words[j];
            words[j] = temp;
         }
      }
   }
}
 
void print_words() {
   int i;
 
   for (i = 0; i < num_words; i++) {
      printf("%s: %d\n", words[i].word, words[i].count);
   }
}
 
int main() {
   char word[MAX_WORD_LENGTH + 1];
   int ch, i;
 
   while (1) {
      i = 0;
      while ((ch = getchar()) != EOF) {
         if (isalpha(ch)) {
            word[i++] = tolower(ch);
            if (i >= MAX_WORD_LENGTH) {
               break;
            }
         } else if (i > 0) {
            word[i] = '\0';
            add_word(word);
            i = 0;
         }
      }
      if (i > 0) {
         word[i] = '\0';
         add_word(word);
      }
      if (ch == EOF) {
         break;
      }
   }
 
   sort_words();
   print_words();
   return 0;
}