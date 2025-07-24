//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *word;
  int count;
} entry_t;

int add_word(entry_t *entries, int num_entries, char *word) {
  for (int i = 0; i < num_entries; i++) {
    if (strcmp(entries[i].word, word) == 0) {
      entries[i].count++;
      return num_entries;
    }
  }
  entry_t new_entry;
  new_entry.word = word;
  new_entry.count = 1;
  entries[num_entries] = new_entry;
  return num_entries + 1;
}

void print_entries(entry_t *entries, int num_entries) {
  printf("Word\tFrequency\n");
  for (int i = 0; i < num_entries; i++) {
    printf("%s\t%d\n", entries[i].word, entries[i].count);
  }
}

int main() {
  char *text = "The quick brown fox jumped over the lazy dog. The lazy dog then ran away with the bone.";
  char *token = strtok(text, " .");
  entry_t entries[100];
  int num_entries = 0;
  while (token != NULL) {
    num_entries = add_word(entries, num_entries, token);
    token = strtok(NULL, " .");
  }
  print_entries(entries, num_entries);
  return 0;
}