//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Sherlock Holmes
/* 
It was a gloomy evening in London when Sherlock Holmes faced a daunting task- to summarize a lengthy document for his client Mr. Jameson who was pressed for time. The detective put on his thinking cap and started coding a C text summarizer program that would do the job in no time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word_node {
   char word[100];
   int freq;
};

int num_words = 0;

void add_word(struct word_node *word_list, char *word) {
   int i;
   for(i = 0; i < num_words; i++) {
      if(!strcmp(word_list[i].word, word)) {
         word_list[i].freq++;
         break;
      }
   }
   if(i == num_words) {
      strcpy(word_list[i].word, word);
      word_list[i].freq = 1;
      num_words++;
   }
}

void bubble_sort(struct word_node *word_list) {
   int i, j;
   struct word_node tmp;
   for(i = 0; i < num_words; i++) {
      for(j = 0; j < num_words-1; j++) {
         if(word_list[j].freq < word_list[j+1].freq) {
            tmp = word_list[j];
            word_list[j] = word_list[j+1];
            word_list[j+1] = tmp;
         }
      }
   }
}

int main() {
   char text[10000] = "It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of Light, it was the season of Darkness, it was the spring of hope, it was the winter of despair.";
   char *token_ptr;
   
   // Tokenize input text
   struct word_node word_list[1000];
   token_ptr = strtok(text, " "); 
   while (token_ptr != NULL) {
      add_word(word_list, token_ptr);
      token_ptr = strtok(NULL, " "); 
   }
   
   // Sort and print top 5 most frequent words
   bubble_sort(word_list);
   printf("The top 5 most frequent words in the input text are:\n");
   int i;
   for(i = 0; i < 5; i++) {
      printf("%s: %d\n", word_list[i].word, word_list[i].freq);
   }

   return 0;
}