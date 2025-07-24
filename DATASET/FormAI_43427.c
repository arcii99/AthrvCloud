//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_NUM_WORDS 10

void print_word_counts(char *str);
int count_words(char *str);
void print_most_common_word(char *str);

int main(void) {
  char str[MAX_STRING_LENGTH];

  printf("Enter a string: ");
  fgets(str, MAX_STRING_LENGTH, stdin);

  print_word_counts(str);
  print_most_common_word(str);

  return 0;
}

void print_word_counts(char *str) {
  int num_words = count_words(str);
  char *words[num_words];
  int counts[num_words];
  int i, j, k, found;

  char *token = strtok(str, " .,!?\n");
  while (token != NULL) {
    found = 0;
    for (i = 0; i < num_words; i++) {
      if (strcmp(token, words[i]) == 0) {
        counts[i]++;
        found = 1;
        break;
      }
    }
    if (!found) {
      words[num_words] = token;
      counts[num_words] = 1;
      num_words++;
    }
    token = strtok(NULL, " .,!?\n");
  }

  printf("Word counts:\n");
  for (i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i], counts[i]);
  }
}

int count_words(char *str) {
  int count = 0;
  char *token = strtok(str, " .,!?\n");
  while (token != NULL) {
    count++;
    token = strtok(NULL, " .,!?\n");
  }
  return count;
}

void print_most_common_word(char *str) {
  int num_words = count_words(str);
  char *words[num_words];
  int counts[num_words];
  int i, j, k, found;

  char *token = strtok(str, " .,!?\n");
  while (token != NULL) {
    found = 0;
    for (i = 0; i < num_words; i++) {
      if (strcmp(token, words[i]) == 0) {
        counts[i]++;
        found = 1;
        break;
      }
    }
    if (!found) {
      words[num_words] = token;
      counts[num_words] = 1;
      num_words++;
    }
    token = strtok(NULL, " .,!?\n");
  }

  char *most_common_word = NULL;
  int most_common_count = 0;

  for (i = 0; i < num_words; i++) {
    if (counts[i] > most_common_count) {
      most_common_word = words[i];
      most_common_count = counts[i];
    }
  }

  printf("Most common word: %s\n", most_common_word);
}