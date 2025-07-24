//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>

int main() {
  char sentence[1000];
  int wordCount= 0;

  printf("Welcome to the C Word Count Tool!\n");
  printf("Please enter the sentence to be counted:\n");

  fgets(sentence, 1000, stdin);

  for (int i = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
      wordCount++;
    }
  }

  if (wordCount == 0) {
    printf("No words detected in the given sentence.\n");
  }
  else {
    printf("The given sentence has %d words!\n", wordCount);
  }
  printf("Thank you for using the C Word Count Tool!");
  return 0;
}