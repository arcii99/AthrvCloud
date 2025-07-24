//FormAI DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  char input[1000];
  int word_count = 0;
  printf("Welcome to the C Word Count Tool!\n");
  printf("Please enter your text:\n");
  fgets(input, sizeof(input), stdin);
  printf("Calculating...\n");

  // Loop through each character in the input string
  for (int i = 0; i < strlen(input); i++) {
    // Check for whitespace or punctuation
    if (isspace(input[i]) || ispunct(input[i])) {
      word_count++;
    }
  }

  // Add one for the last word
  word_count++;

  printf("Total number of words: %d\n", word_count);

  return 0;
}