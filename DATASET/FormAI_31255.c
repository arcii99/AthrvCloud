//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

typedef struct {
  char word[MAX_WORD_LENGTH + 1];
  int count;
} word_count_t;

void count_words(const char *text, word_count_t *word_counts, int *n_words) {
  const char *word_start = text;
  *n_words = 0;
  while (*word_start) {
    // Skip non-alphabetic characters
    while (*word_start && !isalpha(*word_start)) {
      ++word_start;
    }
    // Count the word starting at word_start
    if (*word_start) {
      char *word_end = word_start + 1;
      while (*word_end && isalpha(*word_end)) {
        ++word_end;
      }
      const int word_length = word_end - word_start;
      if (word_length <= MAX_WORD_LENGTH) {
        // Copy the word to a temporary buffer so that we can add a null terminator
        char temp[MAX_WORD_LENGTH + 1];
        memcpy(temp, word_start, word_length);
        // Add a null terminator to make it a string
        temp[word_length] = 0;
        // Increment the word count for this word
        int word_found = 0;
        for (int i = 0; i < *n_words; ++i) {
          if (strcmp(temp, word_counts[i].word) == 0) {
            ++word_counts[i].count;
            word_found = 1;
            break;
          }
        }
        if (!word_found) {
          if (*n_words < MAX_WORDS) {
            strcpy(word_counts[*n_words].word, temp);
            word_counts[*n_words].count = 1;
            ++(*n_words);
          } else {
            fprintf(stderr, "Maximum number of words exceeded!\n");
            exit(1);
          }
        }
      }
      word_start = word_end;
    }
  }
}

int compare_word_counts(const void *p1, const void *p2) {
  const word_count_t *word_count1 = p1;
  const word_count_t *word_count2 = p2;
  return word_count2->count - word_count1->count;
}

int main() {
  char text[100000];
  printf("Enter text (max %ld characters):\n", sizeof(text));
  fgets(text, sizeof(text), stdin);
  // Remove newline from end of text
  text[strcspn(text, "\n")] = 0;
  word_count_t word_counts[MAX_WORDS];
  int n_words;
  count_words(text, word_counts, &n_words);
  qsort(word_counts, n_words, sizeof(word_count_t), compare_word_counts);
  printf("Word Frequencies:\n");
  for (int i = 0; i < n_words; ++i) {
    printf("%s: %d\n", word_counts[i].word, word_counts[i].count);
  }
  return 0;
}