//FormAI DATASET v1.0 Category: Text Summarizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_COUNT 1000
#define MAX_SUMMARY_LENGTH 100

char* summarize(char* text) {
  char* result = calloc(MAX_SUMMARY_LENGTH, sizeof(char));
  char* sentences[MAX_WORD_COUNT];
  char* words[MAX_WORD_COUNT];
  int sentenceCount = 0;
  int wordCount = 0;

  // Split text into sentences
  sentences[sentenceCount++] = strtok(text, ".");
  while (sentences[sentenceCount - 1] != NULL && sentenceCount < MAX_WORD_COUNT) {
    sentences[sentenceCount++] = strtok(NULL, ".");
  }

  // Split each sentence into words
  for (int i = 0; i < sentenceCount; i++) {
    words[wordCount++] = strtok(sentences[i], " ");
    while (words[wordCount - 1] != NULL && wordCount < MAX_WORD_COUNT) {
      words[wordCount++] = strtok(NULL, " ");
    }
    wordCount--;
  }

  // Get the most important words
  int importantWords[wordCount];
  memset(importantWords, 0, sizeof(importantWords));
  for (int i = 0; i < wordCount; i++) {
    for (int j = i + 1; j < wordCount; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        importantWords[i]++;
      }
    }
  }

  // Get the most important sentences
  int importantSentences[sentenceCount];
  memset(importantSentences, 0, sizeof(importantSentences));
  for (int i = 0; i < sentenceCount; i++) {
    for (int j = 0; j < wordCount; j++) {
      if (strstr(sentences[i], words[j]) != NULL) {
        importantSentences[i] += importantWords[j];
      }
    }
  }

  // Concatenate the most important sentences into summary
  for (int i = 0; i < MAX_SUMMARY_LENGTH; i++) {
    int maxIndex = 0;
    for (int j = 1; j < sentenceCount; j++) {
      if (importantSentences[j] > importantSentences[maxIndex]) {
        maxIndex = j;
      }
    }
    importantSentences[maxIndex] = -1; // Remove this sentence from the list of important sentences
    strcat(result, sentences[maxIndex]);
    strcat(result, ".");
  }

  return result;
}

int main() {
  char text[] = "This is a sample text. It contains some sentences. Some of these sentences are more important than others. This means that we need to summarize the text based on the importance of each sentence. The summary should contain only the most important sentences. The other sentences can be excluded.";

  char* summary = summarize(text);
  printf("%s\n", summary);

  free(summary);

  return 0;
}