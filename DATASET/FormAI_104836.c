//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_WORDS 1000

char words[MAX_WORDS][MAX_WORD_SIZE];
int word_counts[MAX_WORDS];
int num_words = 0;

void add_word_to_list(char word[]) {
  // Look through the list of words to see if the word already exists
  for (int i = 0; i < num_words; i++) {
    if (strcmp(words[i], word) == 0) {
      // If the word exists, increment its count
      word_counts[i]++;
      return;
    }
  }

  // If the word does not exist, add it to the list
  strcpy(words[num_words], word);
  word_counts[num_words]++;
  num_words++;
}

int main() {
  // Open the source text file for reading
  FILE* source_file = fopen("source.txt", "r");
  if (source_file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the words from the source file one-by-one
  char current_word[MAX_WORD_SIZE];
  char current_character;
  int word_index = 0;
  while ((current_character = fgetc(source_file)) != EOF) {
    // Ignore punctuation and whitespace characters
    if (isalnum(current_character)) {
      // If the current character is alphanumeric, add it to the current word
      current_word[word_index++] = tolower(current_character);
    } else if (word_index != 0) {
      // If the current character is not alphanumeric and we have already started a word,
      // add the current word to the list and reset the word index for the next word
      current_word[word_index] = '\0';
      add_word_to_list(current_word);
      word_index = 0;
    }
  }

  // Print out the list of words and their counts
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i], word_counts[i]);
  }

  // Close the source file
  fclose(source_file);

  return 0;
}