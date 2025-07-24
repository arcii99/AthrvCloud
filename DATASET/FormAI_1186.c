//FormAI DATASET v1.0 Category: Text Summarizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_LENGTH 100

char* text_summarizer(char* text) {
  char* summary = (char*) malloc(sizeof(char) * MAX_SUMMARY_LENGTH);
  int text_len = strlen(text);

  if (text_len == 0) {
    strcpy(summary, "No text to summarize.");
    return summary;
  }

  // remove whitespace and punctuation
  char* clean_text = (char*) malloc(sizeof(char) * text_len);
  int j = 0;
  for (int i = 0; i < text_len; i++) {
    if (text[i] != ' ' && text[i] != '.' && text[i] != ',' &&
        text[i] != '?' && text[i] != '!' && text[i] != ':' &&
        text[i] != ';' && text[i] != '-') {
      clean_text[j++] = text[i];
    }
  }

  // split text into sentences
  char* sentence = strtok(clean_text, ".!?");

  // track highest scoring sentences
  char* top_sentences[MAX_SUMMARY_LENGTH / 2];
  int top_scores[MAX_SUMMARY_LENGTH / 2];
  int num_top_sentences = 0;
  int min_top_score = 0;

  // score each sentence and keep track of top sentences
  while (sentence != NULL) {
    int sentence_len = strlen(sentence);
    int score = 0;
    for (int i = 0; i < sentence_len; i++) {
      score += sentence[i] - 'a'; // assign score based on alphabetical position
    }

    if (num_top_sentences < MAX_SUMMARY_LENGTH / 2 ||
        score > min_top_score) {
      if (num_top_sentences == MAX_SUMMARY_LENGTH / 2) {
        // remove lowest scoring sentence
        int min_index = 0;
        for (int i = 1; i < MAX_SUMMARY_LENGTH / 2; i++) {
          if (top_scores[i] < top_scores[min_index]) {
            min_index = i;
          }
        }
        free(top_sentences[min_index]);
        top_sentences[min_index] = NULL;
        num_top_sentences--;
        min_top_score = top_scores[min_index];
      }

      // add sentence to top sentences
      char* sentence_copy = (char*) malloc(sizeof(char) * sentence_len + 1);
      strcpy(sentence_copy, sentence);
      top_sentences[num_top_sentences] = sentence_copy;
      top_scores[num_top_sentences] = score;
      num_top_sentences++;

      if (score < min_top_score) {
        min_top_score = score;
      }
    }

    // move to next sentence
    sentence = strtok(NULL, ".!?");
  }

  // create summary from top sentences
  strcpy(summary, "");
  for (int i = 0; i < num_top_sentences; i++) {
    strcat(summary, top_sentences[i]);
    if (i < num_top_sentences - 1) {
      strcat(summary, ". ");
    }
  }

  free(clean_text);
  for (int i = 0; i < num_top_sentences; i++) {
    free(top_sentences[i]);
  }

  return summary;
}

int main() {
  char* text = "John went to the store to buy some eggs. On his way there, he saw a dog chasing a cat. The cat ran up a tree and the dog gave up. John arrived at the store and bought a dozen eggs.";

  char* summary = text_summarizer(text);

  printf("Original text:\n%s\n", text);
  printf("Summary:\n%s\n", summary);

  free(summary);
}