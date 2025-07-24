//FormAI DATASET v1.0 Category: Word Count Tool ; Style: curious
#include <stdio.h>

// Define the maximum characters in a word
#define MAX_WORD_LENGTH 50

int main() {
  char inputString[500];
  int wordCount = 0, charCount = 0;
  char currentChar = ' ';

  // Prompt the user for input text
  printf("Please enter some text: ");

  // Read the user's input text into the inputString variable
  fgets(inputString, sizeof(inputString), stdin);

  // Loop through each character in the inputString variable
  for (int i = 0; inputString[i] != '\0'; i++) {
    currentChar = inputString[i];

    // If the current character is not a space or new line, increment the charCount
    if (currentChar != ' ' && currentChar != '\n') {
      charCount++;
    }

    // If the current character is a space, increment the wordCount and reset the charCount
    if (currentChar == ' ') {
      wordCount++;
      charCount = 0;
    }

    // If the charCount reaches the maximum word length, truncate the word and increment count
    if (charCount == MAX_WORD_LENGTH) {
      printf("Word truncated: %.*s\n", MAX_WORD_LENGTH, &inputString[i - MAX_WORD_LENGTH + 1]);
      wordCount++;
      charCount = 0;
    }
  }

  // Increment count for the final word, as there is no following space
  if (currentChar != ' ' && currentChar != '\n') {
    wordCount++;
  }

  // Output the total word count
  printf("Total word count: %d\n", wordCount);

  return 0;
}