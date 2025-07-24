//FormAI DATASET v1.0 Category: Text Summarizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LEN 1000

int main(int argc, char *argv[]) {
  char text[MAX_SENTENCE_LEN * MAX_SENTENCES]; // Full text
  char sentences[MAX_SENTENCES][MAX_SENTENCE_LEN]; // Individual sentences
  char *p_sentences[MAX_SENTENCES]; // Pointer array to sentences
  int n_sentences; // Number of sentences
  char summary[MAX_SENTENCE_LEN * MAX_SENTENCES]; // Summary text
  int n_summary_sentences; // Number of summary sentences
  double weights[MAX_SENTENCES]; // Weight of each sentence
  int i;

  // Get the text
  printf("Enter the text:\n");
  fgets(text, MAX_SENTENCE_LEN * MAX_SENTENCES, stdin);

  // Split the text into sentences
  n_sentences = 0;
  p_sentences[n_sentences] = strtok(text, ".!?"); // Get the first sentence
  while (p_sentences[n_sentences] != NULL) { // Keep getting sentences until there are none left
    n_sentences++;
    p_sentences[n_sentences] = strtok(NULL, ".!?");
  }

  // Calculate the weight of each sentence
  for (i = 0; i < n_sentences; i++) {
    // Count the number of words in the sentence
    int n_words = 0;
    char *p_word = strtok(p_sentences[i], " ");
    while (p_word != NULL) {
      n_words++;
      p_word = strtok(NULL, " ");
    }
    weights[i] = (double) n_words / (double) n_sentences;
  }

  // Sort the sentences by weight
  for (i = 0; i < n_sentences - 1; i++) {
    int j;
    for (j = i + 1; j < n_sentences; j++) {
      if (weights[j] > weights[i]) {
        double temp_weight = weights[i];
        weights[i] = weights[j];
        weights[j] = temp_weight;
        char *temp_pointer = p_sentences[i];
        p_sentences[i] = p_sentences[j];
        p_sentences[j] = temp_pointer;
      }
    }
  }

  // Select the top sentences for the summary
  n_summary_sentences = n_sentences / 2;
  for (i = 0; i < n_summary_sentences; i++) {
    strcat(summary, p_sentences[i]);
    strcat(summary, ". ");
  }

  // Print the summary
  printf("Summary:\n%s\n", summary);

  return 0;
}