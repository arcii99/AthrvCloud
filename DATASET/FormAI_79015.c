//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

// Struct to store each unique word and its frequency count
typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} WordCount;

// Function prototypes
int compFunc(const void * a, const void * b);
bool isNewWord(char *word, WordCount *wordCounts, int wordCountSize);

int main() {

  // Array to store all the unique words and their frequency count
  WordCount wordCounts[MAX_WORD_LENGTH];
  int wordCountSize = 0;

  // Array to store the current word being read
  char currentWord[MAX_WORD_LENGTH] = "";
  
  // Variables to store characters read from input
  char c;
  int i = 0;

  // Read from stdin until EOF is encountered
  while ((c = getchar()) != EOF) {

    // If the current character is not alphabetic, then assume it is the end of a word
    if (!isalpha(c)) {

      // Ensure the word being read is longer than 0 characters
      if (i > 0) {

        // Convert the word to lowercase
        for (int j = 0; j < i; j++) {
          currentWord[j] = tolower(currentWord[j]);
        }

        // If the word is new, add it to the array of unique words and initialize its frequency count to 1
        if (isNewWord(currentWord, wordCounts, wordCountSize)) {
          strcpy(wordCounts[wordCountSize].word, currentWord);
          wordCounts[wordCountSize].count = 1;
          wordCountSize++;
        }
        // Otherwise, increment the existing word's frequency count
        else {
          for (int j = 0; j < wordCountSize; j++) {
            if (strcmp(currentWord, wordCounts[j].word) == 0) {
              wordCounts[j].count++;
              break;
            }
          }
        }

        // Reset the currentWord array for the next word
        memset(currentWord, 0, sizeof(currentWord));
        i = 0;
      }
    }
    // Otherwise, add the current character to the currentWord array
    else {
      currentWord[i++] = c;
    }
  }

  // Sort the array of unique words by their frequency count, in descending order
  qsort(wordCounts, wordCountSize, sizeof(WordCount), compFunc);

  // Output the final results
  for (int j = 0; j < wordCountSize; j++) {
    printf("%s - %d\n", wordCounts[j].word, wordCounts[j].count);
  }

  return 0;
}

// Comparison function for qsort, sorts by descending frequency count
int compFunc(const void * a, const void * b) {
  WordCount *wcA = (WordCount *) a;
  WordCount *wcB = (WordCount *) b;
  return (wcB->count - wcA->count);
}

// Checks whether the given word is already in the array of unique words
bool isNewWord(char *word, WordCount *wordCounts, int wordCountSize) {
  for (int i = 0; i < wordCountSize; i++) {
    if (strcmp(word, wordCounts[i].word) == 0) {
      return false;
    }
  }
  return true;
}