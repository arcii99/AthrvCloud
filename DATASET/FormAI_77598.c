//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Word Count Tool - Surprised Edition!\n");
  printf("Enter a sentence to count the words in it: ");

  // Reading input from user
  char sentence[200];
  fgets(sentence, sizeof(sentence), stdin);

  // Word count logic
  int words = 1; // At least one word in a sentence
  for (int i = 0; sentence[i] != '\0'; ++i) {
    if (sentence[i] == ' ' || sentence[i] == '\n') {
      words++;
    }
  }

  // Result output 
  printf("\nSurprise! Your sentence has %d words! :D\n", words);

  // Easter egg
  if (words == 3) {
    printf("\nWow, what a coincidence! Three is a magical number. Keep it up!\n");
  }
  return 0;
}