//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

int main() {
  char input[MAX_INPUT_LENGTH];
  int wordCount = 0;
  int charCount = 0;
  int flag = 0;

  printf("Welcome to the C Word Count Tool!\n");
  printf("Please enter your text below (maximum %d characters):\n", MAX_INPUT_LENGTH);
  fgets(input, sizeof(input), stdin);

  for(int i = 0; i < strlen(input); i++) {
    // Increment character count for every non-whitespace character
    if(input[i] != ' ' && input[i] != '\n' && input[i] != '\t') {
      charCount++;
      flag = 1;
    }
    // If whitespace character encountered and previous character was not whitespace, increment word count
    if((input[i] == ' ' || input[i] == '\n' || input[i] == '\t') && flag) {
      wordCount++;
      flag = 0;
    }
  }

  // Increment word count if input ends with non-whitespace character
  if(flag) {
    wordCount++;
  }

  printf("\n");
  printf("Word Count: %d\n", wordCount);
  printf("Character Count: %d\n", charCount);

  return 0;
}