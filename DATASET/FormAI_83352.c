//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant values for summarization algorithm
#define SENTENCE_COUNT 3
#define MIN_SENTENCE_LENGTH 10
#define MAX_WORD_COUNT 20
#define MAX_SUMMARY_LENGTH 200

int main() {
  char input_text[1000];
  char *sentences[SENTENCE_COUNT];
  int sentence_word_count[SENTENCE_COUNT];
  int total_words = 0;
  int summary_word_count = 0;
  char summary[MAX_SUMMARY_LENGTH];
  
  // Get input text from user
  printf("Enter input text:\n");
  fgets(input_text, sizeof(input_text), stdin);

  // Tokenize input text into sentences
  char *sentence = strtok(input_text, ".?!"); 
  int i = 0;
  while (sentence != NULL && i < SENTENCE_COUNT) {
    // Only consider sentences with a minimum length
    if (strlen(sentence) > MIN_SENTENCE_LENGTH) {
      sentences[i] = sentence;
      i++;
    }
    sentence = strtok(NULL, ".?!");
  }
  int sentence_count = i;
  
  // Calculate number of words in each sentence
  for (i = 0; i < sentence_count; i++) {
    char *word = strtok(sentences[i], " ");
    int word_count = 0;
    while (word != NULL && word_count < MAX_WORD_COUNT) {
      word_count++;
      word = strtok(NULL, " ");
    }
    sentence_word_count[i] = word_count;
    total_words += word_count;
  }
  
  // Determine the percentage of word count for each sentence
  for (i = 0; i < sentence_count; i++) {
    float percentage = (float)sentence_word_count[i] / (float)total_words;
    int summary_sentence_word_count = percentage * MAX_WORD_COUNT;
    if (summary_word_count + summary_sentence_word_count < MAX_SUMMARY_LENGTH) {
      strncat(summary, sentences[i], summary_sentence_word_count);
      strncat(summary, ". ", 2);
      summary_word_count += summary_sentence_word_count + 2;
    }
  }
  
  // Output summary
  printf("\nSummary:\n%s\n", summary);

  return 0;
}