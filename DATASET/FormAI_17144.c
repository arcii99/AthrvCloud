//FormAI DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 512

int main() {
  // Initialize variables
  char line[MAX_LINE_LENGTH];
  int line_count = 0;
  int char_count = 0;
  int word_count = 0;

  // Prompt user for input
  printf("Please enter some text:\n");

  // Read in each line of input
  while (fgets(line, MAX_LINE_LENGTH, stdin)) {
    // Increment line count
    line_count++;

    // Strip newline character from end of line
    line[strcspn(line, "\n")] = '\0';

    // Loop through each character in the line
    for (int i = 0; line[i] != '\0'; i++) {
      // Increment char count
      char_count++;

      // Check if current character is part of a word
      if (!isspace(line[i]) && (i == 0 || isspace(line[i - 1]))) {
        // Increment word count
        word_count++;
      }
    }
  }

  // Print out results
  printf("You entered %d lines of text.\n", line_count);
  printf("There are %d characters in the text.\n", char_count);
  printf("There are %d words in the text.\n", word_count);

  return 0;
}