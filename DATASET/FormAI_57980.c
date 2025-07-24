//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_WORDS 1000

struct word_count {
  char word[MAX_WORD_LENGTH];
  int count;
};

bool is_word_char(char c) {
  if (c == '\'' || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    return true;
  } else {
    return false;
  }
}

void to_lower_case(char *word) {
  int i;
  for(i = 0; word[i]; i++){
    word[i] = tolower(word[i]);
  }
}

bool is_stop_word(char *word) {
  char *stop_words[] = {"the", "a", "an", "and", "is", "are", "was", "were", "it", "in", "at", "of", "that", "this", "with", "for", "to", "on", "or", "as", "by", "if", "not", "from"};
  int num_words = sizeof(stop_words) / sizeof(stop_words[0]);
  int i;
  for (i = 0; i < num_words; i++) {
    if (strcmp(stop_words[i], word) == 0) {
      return true;
    }
  }
  return false;
}

int word_count_cmp(const void *p1, const void *p2) {
  const struct word_count *wc1 = (const struct word_count *) p1;
  const struct word_count *wc2 = (const struct word_count *) p2;
  if (wc1->count > wc2->count) {
    return -1;
  } else if (wc1->count < wc2->count) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  // set up word count array
  struct word_count word_counts[MAX_WORDS];
  int num_words = 0;

  // read in words from input
  char word[MAX_WORD_LENGTH];
  bool in_word = false;
  int i;
  char c;
  while ((c = getchar()) != EOF && num_words < MAX_WORDS) {
    if (is_word_char(c)) {
      if (!in_word) {
        in_word = true;
        i = 0;
      }
      if (i < MAX_WORD_LENGTH - 1) {
        word[i++] = c;
      }
    } else {
      if (in_word) {
        word[i] = '\0';
        to_lower_case(word);
        if (!is_stop_word(word)) { // only count non-stop words
          int j;
          for (j = 0; j < num_words; j++) {
            if (strcmp(word_counts[j].word, word) == 0) { // if word already counted before
              word_counts[j].count++;
              break;
            }
          }
          if (j == num_words) { // if word not counted before
            strcpy(word_counts[num_words].word, word);
            word_counts[num_words].count = 1;
            num_words++;
          }
        }
        in_word = false;
      }
    }
  }

  // sort word count array in descending order
  qsort(word_counts, num_words, sizeof(struct word_count), word_count_cmp);

  // print out word count array
  for (i = 0; i < num_words; i++) {
    printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
  }

  return 0;
}