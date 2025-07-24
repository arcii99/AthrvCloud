//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct word_freq {
  char word[MAX_WORD_LENGTH];
  int freq;
} word_freq_t;

void add_word(char *word, word_freq_t *freq_arr, int *num_words) {
  int i;
  for (i = 0; i < *num_words; i++) {
    if (strcmp(word, freq_arr[i].word) == 0) { // If word is already in freq_arr, increment its frequency
      freq_arr[i].freq++;
      return;
    }
  }
  // If word is not in freq_arr, add it, with frequency = 1
  strcpy(freq_arr[*num_words].word, word);
  freq_arr[*num_words].freq = 1;
  (*num_words)++;
}

void print_freq_arr(word_freq_t *freq_arr, int num_words) {
  printf("Word\tFrequency\n");
  for (int i = 0; i < num_words; i++) {
    printf("%s\t%d\n", freq_arr[i].word, freq_arr[i].freq);
  }
}

int main() {
  char input_string[MAX_WORDS * MAX_WORD_LENGTH];
  printf("Enter a string: ");
  fgets(input_string, MAX_WORDS * MAX_WORD_LENGTH, stdin);

  // Remove newline character at the end of input_string, if present
  int last_char_index = strlen(input_string) - 1;
  if (last_char_index >= 0 && input_string[last_char_index] == '\n') {
    input_string[last_char_index] = '\0';
  }

  word_freq_t freq_arr[MAX_WORDS];
  int num_words = 0;

  char *word_ptr; // Pointer to the current word in the input string
  char *delimiters = " .,!?\t"; // Possible delimiters between words
  word_ptr = strtok(input_string, delimiters); // Get first word
  while (word_ptr != NULL) { // Loop through all words in input_string
    add_word(word_ptr, freq_arr, &num_words);
    word_ptr = strtok(NULL, delimiters); // Get next word
  }

  // Print the word frequency array
  print_freq_arr(freq_arr, num_words);

  return 0;
}