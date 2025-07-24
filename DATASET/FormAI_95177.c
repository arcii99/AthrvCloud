//FormAI DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_SENTENCES 100
#define MAX_KEYWORDS 50
#define MAX_SUMMARY_LENGTH 500

int count(char *str, char *substr) {
  int count = 0;
  char *pos = strstr(str, substr);
  while (pos != NULL) {
    count++;
    pos = strstr(pos + 1, substr);
  }
  return count;
}

int main() {

  // Read input text
  char text[MAX_LINE_LENGTH];
  fgets(text, MAX_LINE_LENGTH, stdin);

  // Split text into sentences
  char *sentences[MAX_SENTENCES];
  char *token = strtok(text, ".?!");
  int num_sentences = 0;
  while (token != NULL && num_sentences < MAX_SENTENCES) {
    sentences[num_sentences] = token;
    num_sentences++;
    token = strtok(NULL, ".?!");
  }

  // Read keywords
  char keywords[MAX_KEYWORDS][MAX_LINE_LENGTH];
  int num_keywords = 0;
  fgets(keywords[num_keywords], MAX_LINE_LENGTH, stdin);
  while (keywords[num_keywords][0] != '\n' && num_keywords < MAX_KEYWORDS) {
    num_keywords++;
    fgets(keywords[num_keywords], MAX_LINE_LENGTH, stdin);
  }

  // Compute sentence scores
  float scores[MAX_SENTENCES];
  for (int i = 0; i < num_sentences; i++) {
    scores[i] = 0;
    for (int j = 0; j < num_keywords; j++) {
      scores[i] += count(sentences[i], keywords[j]);
    }
    scores[i] /= strlen(sentences[i]);
  }

  // Select top sentences for summary
  char summary[MAX_SUMMARY_LENGTH];
  summary[0] = '\0';
  while (strlen(summary) < MAX_SUMMARY_LENGTH && num_sentences > 0) {
    int max_index = 0;
    for (int i = 1; i < num_sentences; i++) {
      if (scores[i] > scores[max_index]) {
        max_index = i;
      }
    }
    strcat(summary, sentences[max_index]);
    strcat(summary, ". ");
    scores[max_index] = 0;
    for (int i = 0; i < num_keywords; i++) {
      scores[max_index] -= count(sentences[max_index], keywords[i]);
    }
    scores[max_index] /= strlen(sentences[max_index]);
    num_sentences--;
  }

  // Print summary
  printf("%s\n", summary);

  return 0;
}