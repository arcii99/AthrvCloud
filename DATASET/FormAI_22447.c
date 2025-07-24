//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // Maximum length of a word
#define MAX_WORDS 1000 // Maximum number of unique words to track frequency
#define BUFFER_SIZE 10000 // Maximum size of input text

// Struct to hold a word and its frequency
typedef struct {
  char word[MAX_WORD_LENGTH];
  int frequency;
} word_freq;

// Function to check if a word already exists in the array of words
int wordExists(char word[], word_freq words[], int num_words) {
  for (int i = 0; i < num_words; i++) {
    if (strcmp(words[i].word, word) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  char buffer[BUFFER_SIZE];
  word_freq words[MAX_WORDS];
  int num_words = 0;

  // Read in input text from user
  printf("Enter some text:\n");
  fgets(buffer, BUFFER_SIZE, stdin);

  // Loop through input text and extract each word
  int i = 0;
  char word[MAX_WORD_LENGTH];
  while (buffer[i]) {
    // Ignore non-alphabetic characters
    if (isalpha(buffer[i])) {
      // Convert character to lowercase and add to word
      word[strlen(word)] = tolower(buffer[i]);
    }
    // If we've found a whole word, add it to the array of words
    else if (strlen(word) > 0) {
      // Check if word already exists in array
      int index = wordExists(word, words, num_words);
      if (index >= 0) {
        // Increment frequency of word
        words[index].frequency++;
      }
      else {
        // Add new word to array
        strcpy(words[num_words].word, word);
        words[num_words].frequency = 1;
        num_words++;
      }
      // Reset word for next iteration
      word[0] = '\0';
    }
    i++;
  }

  // Print out the frequency of each word
  printf("Word Frequency:\n");
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i].word, words[i].frequency);
  }

  return 0;
}