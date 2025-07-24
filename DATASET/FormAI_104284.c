//FormAI DATASET v1.0 Category: Text Summarizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SENTENCES 10
#define MAX_SENTENCE_LENGTH 500

char summary[MAX_SENTENCE_LENGTH * MAX_SENTENCES];

char *summarize(char *input, int sentences) {
  char *start = input;
  int len = strlen(input);
  int i;
  int sentence_count = 0;
  for(i = 0; i < len; i++) {
    if(input[i] == '.' || input[i] == '!' || input[i] == '?') {
      sentence_count++;
      if(sentence_count == sentences) {
        int summary_len = start - input + i + 1;
        strncpy(summary, input, summary_len);
        summary[summary_len] = '\0';
        return summary;
      }
      else {
        start = input + i + 1;
      }
    }
  }
  strncpy(summary, input, len);
  summary[len] = '\0';
  return summary;
}

int main() {
  char input[MAX_SENTENCE_LENGTH * MAX_SENTENCES];
  fgets(input, MAX_SENTENCE_LENGTH * MAX_SENTENCES, stdin);
  printf("%s", summarize(input, 3));
  return 0;
}