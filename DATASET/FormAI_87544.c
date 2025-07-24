//FormAI DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000
#define MAX_CHARACTERS 1000

char sentences[MAX_SENTENCES][MAX_CHARACTERS];
char words[MAX_WORDS][MAX_CHARACTERS];

int sentenceCount = 0;
int wordCount = 0;

void tokenizeSentences(char *text) {
  char *sentence;
  sentence = strtok(text, ".?!");

  while (sentence != NULL) {
    strcpy(sentences[sentenceCount], sentence);
    sentenceCount++;
    sentence = strtok(NULL, ".?!");
  }
}

void tokenizeWords(char *sentence) {
  char *word;
  word = strtok(sentence, " ");

  while (word != NULL) {
    strcpy(words[wordCount], word);
    wordCount++;
    word = strtok(NULL, " ");
  }
}

void removeDuplicateSentences() {
  int i, j;
  for (i = 0; i < sentenceCount; i++) {
    for (j = 0; j < sentenceCount; j++) {
      if (i == j) {
        continue;
      }

      if (strcmp(sentences[i], sentences[j]) == 0) {
        memset(sentences[j], 0, MAX_CHARACTERS);
      }
    }
  }
}

int main() {
  char text[MAX_CHARACTERS];

  printf("Enter some text: ");
  fgets(text, MAX_CHARACTERS, stdin);

  tokenizeSentences(text);

  int i;
  for (i = 0; i < sentenceCount; i++) {
    tokenizeWords(sentences[i]);
  }

  removeDuplicateSentences();

  printf("\nSummary:\n\n");
  for (i = 0; i < sentenceCount; i++) {
    if (strlen(sentences[i]) > 0) {
      printf("%s. ", sentences[i]);
    }
  }

  return 0;
}