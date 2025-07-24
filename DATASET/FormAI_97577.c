//FormAI DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <ctype.h>

int main() {
  // Introduction
  printf("Welcome to the futuristic Word Count Tool!\n");
  printf("Enter a sentence and we'll count the number of words:\n");

  // Input Sentence
  char sentence[1000];
  fgets(sentence, 1000, stdin);

  // Counting Words
  int count = 0;
  int state = 0; // 0 for whitespace, 1 for non-whitespace

  for (int i = 0; sentence[i] != '\0'; i++) {
    if (isspace(sentence[i])) {
      state = 0;
    } else if (state == 0) {
      state = 1;
      count++;
    }
  }

  // Displaying Results
  if (count == 1) {
    printf("There is 1 word in the sentence.\n");
  } else {
    printf("There are %d words in the sentence.\n", count);
  }

  // Goodbye
  printf("Thank you for using the Word Count Tool. Goodbye!\n");

  return 0;
}