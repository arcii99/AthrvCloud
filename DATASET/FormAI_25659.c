//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} WordFreq;

typedef struct {
  WordFreq* data;
  int size;
} WordFreqList;

void add_word(WordFreqList* list, char* word) {
  // Make word lowercase
  for (int i = 0; i < strlen(word); i++) {
    word[i] = tolower(word[i]);
  }

  // Check if word already exists
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->data[i].word, word) == 0) {
      list->data[i].count++;
      return;
    }
  }

  // Add new word to list
  strcpy(list->data[list->size].word, word);
  list->data[list->size].count = 1;
  list->size++;
}

WordFreqList* word_frequency(char* text) {
  WordFreqList* list = malloc(sizeof(WordFreqList));
  list->data = malloc(sizeof(WordFreq) * strlen(text));
  list->size = 0;
  
  char word[MAX_WORD_LENGTH] = "";
  int index = 0;

  for (int i = 0; i < strlen(text); i++) {
    if (isalpha(text[i])) {
      // Add character to current word
      word[index] = text[i];
      index++;
    } else {
      // Add completed word to list
      if (index > 0) {
        word[index] = '\0';
        add_word(list, word);
        index = 0;
        memset(word, 0, sizeof(word));
      }
    }
  }

  // Add final word to list
  if (index > 0) {
    word[index] = '\0';
    add_word(list, word);
  }

  return list;
}

void print_word_freq(WordFreqList* list) {
  for (int i = 0; i < list->size; i++) {
    printf("%s: %d\n", list->data[i].word, list->data[i].count);
  }
}

int main() {
  char text[] = "The quick brown fox jumped over the lazy dog. The dog slept in the moonlight.";

  WordFreqList* list = word_frequency(text);
  print_word_freq(list);

  free(list->data);
  free(list);

  return 0;
}