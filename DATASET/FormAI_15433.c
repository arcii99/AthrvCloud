//FormAI DATASET v1.0 Category: Text Summarizer ; Style: future-proof
/* 
   C Text Summarizer Example Program 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000 // max length of input text
#define MAX_SENTENCES 10 // max number of sentences in summary
#define MAX_SUMMARY 200 // max length of summary

// function to strip punctuation from a string
void strip_punct(char *s) {
   for (; *s; ++s) {
      if (ispunct(*s)) {
         *s = ' ';
      }
   }
}

// function to count sentences in a string
int count_sentences(char *s) {
   int count = 0;
   for (; *s; ++s) {
      if (*s == '.' || *s == '?' || *s == '!') {
         count++;
      }
   }
   return count;
}

int main() {
   // input text buffer
   char input_text[MAX_LEN];
   printf("Enter text to summarize:\n");
   fgets(input_text, MAX_LEN, stdin);

   // strip punctuation from input text
   strip_punct(input_text);

   // count number of sentences in input text
   int num_sentences = count_sentences(input_text);

   // split input text into individual sentences
   char *token;
   char sentences[num_sentences][MAX_LEN];
   token = strtok(input_text, ".?!");
   int i = 0;
   while (token != NULL) {
      strcpy(sentences[i], token);
      token = strtok(NULL, ".?!");
      i++;
   }

   // get top 10 sentences with highest word count
   int top_sentences[MAX_SENTENCES];
   int sentence_word_counts[num_sentences];
   for (int i = 0; i < num_sentences; i++) {
      sentence_word_counts[i] = 0;
      char *word_token;
      word_token = strtok(sentences[i], " ");
      while (word_token != NULL) {
         sentence_word_counts[i]++;
         word_token = strtok(NULL, " ");
      }
   }
   for (int i = 0; i < MAX_SENTENCES; i++) { // initialize top_sentences with -1
      top_sentences[i] = -1;
   }
   for (int i = 0; i < num_sentences; i++) {
      for (int j = 0; j < MAX_SENTENCES; j++) {
         if (top_sentences[j] == -1 || sentence_word_counts[i] > sentence_word_counts[top_sentences[j]]) {
            // shift all entries greater than j to the right
            for (int k = MAX_SENTENCES - 2; k >= j; k--) {
               top_sentences[k+1] = top_sentences[k];
            }
            top_sentences[j] = i;
            break;
         }
      }
   }

   // concatenate top 10 sentences into summary
   char summary[MAX_SUMMARY];
   strcpy(summary, "");
   for (int i = 0; i < MAX_SENTENCES && top_sentences[i] != -1; i++) {
      strcat(summary, sentences[top_sentences[i]]);
   }

   // output summary
   printf("Summary:\n%s", summary);

   return 0;
}