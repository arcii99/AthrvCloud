//FormAI DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000
#define MAX_SENTENCES 500
#define MAX_WORDS_PER_SENTENCE 100

struct Sentence {
  char words[MAX_WORDS_PER_SENTENCE][50];
  int numWords;
};

int numSentences;
char text[MAX_LEN];
struct Sentence sentences[MAX_SENTENCES];

void read_input() {
  fgets(text, MAX_LEN, stdin);
  numSentences = 0;
  int i = 0;
  char *word = strtok(text, " ");
  while (word) {
    if (numSentences == 0 || word[strlen(word) - 1] == '.') {
      struct Sentence sentence;
      sentence.numWords = 0;
      sentences[numSentences] = sentence;
      numSentences++;
      i = 0;
    }
    strcpy(sentences[numSentences - 1].words[i++], word);
    sentences[numSentences - 1].numWords++;
    word = strtok(NULL, " ");
  }
}

int score(struct Sentence sentence) {
  int score = 0;
  for (int i = 0; i < sentence.numWords; i++) {
    if (strlen(sentence.words[i]) > 6) {
      score++;
    }
  }
  return score;
}

int cmpScore(const void *a, const void *b) {
  return score(*(struct Sentence *)b) - score(*(struct Sentence *)a);
}

void summarize() {
  qsort(sentences, numSentences, sizeof(struct Sentence), cmpScore);
  for (int i = 0; i < (numSentences >= 10 ? 10 : numSentences); i++) {
    for (int j = 0; j < sentences[i].numWords; j++) {
      printf("%s ", sentences[i].words[j]);
    }
  }
  printf("\n");
}

int main() {
  read_input();
  summarize();
  return 0;
}