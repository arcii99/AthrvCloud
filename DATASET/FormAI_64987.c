//FormAI DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Function to check whether a given word is spelled correctly or not
int spell_check(char* word) {
  // List of valid words in the dictionary
  char* dictionary[] = {"algorithm", "computer", "programming", "language", 
                        "variable", "function", "pointer", "syntax", "compiler"};

  for (int i = 0; i < 9; i++) {
    if (strcmp(word, dictionary[i]) == 0) {
      // Word found in the dictionary
      return 1;
    }
  }

  // Word not found in the dictionary
  return 0;
}

int main() {
  // Input string to spell check
  char str[100];

  // Prompt user to enter a string
  printf("Enter a sentence to check for spelling errors:\n");
  fgets(str, 100, stdin);

  // Tokenize the input string to extract individual words
  char* words = strtok(str, " .,!?:;\n");

  // Loop through each word and spell check them
  while (words != NULL) {
    if (spell_check(words) == 1) {
      printf("%s is spelled correctly.\n", words);
    } else {
      printf("%s is misspelled.\n", words);
    }
    words = strtok(NULL, " .,!?:;\n");
  }

  return 0;
}