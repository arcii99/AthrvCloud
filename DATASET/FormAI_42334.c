//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

int main() {
  char input_str[1000];
  int word_count = 0;

  printf("Enter a sentence: ");
  fgets(input_str, sizeof(input_str), stdin);

  char *token = strtok(input_str, " ");
  while (token != NULL) {
    if (strlen(token) <= MAX_WORD_LENGTH) {
      word_count++;
    }
    token = strtok(NULL, " ");
  }

  printf("The number of words with length less than or equal to 50: %d\n", word_count);

  return 0;
}