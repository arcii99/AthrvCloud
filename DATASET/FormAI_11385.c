//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <string.h>

// define constants
#define MAX_INPUT_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 100

int main() {
  // initialize variables
  char input[MAX_INPUT_LENGTH];
  char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
  int wordCount[MAX_NUM_WORDS] = {0};
  int numWords = 0;

  // read input from user
  printf("Please enter your text:\n");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // determine number of words and store them in array
  char* token = strtok(input, " ,.?!:;\n");
  while (token != NULL && numWords < MAX_NUM_WORDS) {
    strcpy(words[numWords], token);
    numWords++;
    token = strtok(NULL, " ,.?!:;\n");
  }

  // count occurrence of each word
  for (int i = 0; i < numWords; i++) {
    for (int j = 0; j < numWords; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        wordCount[i]++;
      }
    }
  }

  // print result
  printf("\nWord count:\n");
  for (int i = 0; i < numWords; i++) {
    if (wordCount[i] > 0) {
      printf("%s: %d\n", words[i], wordCount[i]);
    }
  }

  return 0;
}