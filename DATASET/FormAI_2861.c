//FormAI DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <ctype.h>

int main() {
  char input[1000];
  int characterCount = 0;
  int wordCount = 1;
  int lineCount = 1;

  printf("Enter your text here: \n");

  // Take user input until the character '\0' is encountered
  while (fgets(input, 1000, stdin)) {

    // Count the number of characters
    for(int i = 0; i < strlen(input); i++) {
      characterCount++;
    }

    // Count the number of words
    for(int i = 0; i < strlen(input); i++) {
      if(input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
        wordCount++;
      }
    }

    // Count the number of new lines
    for(int i = 0; i < strlen(input); i++) {
      if(input[i] == '\n') {
        lineCount++;
      }
    }
  }

  // Remove extra wordCount due to the blank space after the final word
  wordCount--;

  printf("\nRESULT:\n");
  printf("-------------\n");
  printf("Character Count: %d\n", characterCount);
  printf("Word Count: %d\n", wordCount);
  printf("Line Count: %d\n", lineCount);

  return 0;
}