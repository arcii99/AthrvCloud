//FormAI DATASET v1.0 Category: Spell checking ; Style: mind-bending
#include <stdio.h>
#include <ctype.h>

int main() {
  char text[1000];
  char dictionary[100][100] = {"cat", "dog", "bird", "fish", "snake", "hamster", "mouse", "horse", "monkey", "elephant", "lion", "tiger", "giraffe", "zebra", "kangaroo", "crocodile", "hippopotamus", "rhinoceros", "shark", "whale"};
  int numWords = 20;
  int wordCount = 0;
  int misspellings = 0;
  int i, j, k;

  printf("Enter text for spell checking:\n");
  fgets(text, 1000, stdin);

  for (i = 0; text[i] != '\0'; i++) {

    // If the current character is not an alphabet, it's the end of a word
    if (!isalpha(text[i]) && text[i] != '\'') {
      // Make sure it's not just an apostrophe on its own
      if (wordCount > 0) {
        // Check if the word is in the dictionary
        int found = 0;
        for (j = 0; j < numWords; j++) {
          if (strcmp(text + i - wordCount, dictionary[j]) == 0) {
            found = 1;
            break;
          }
        }
        if (!found) {
          // The word is not in the dictionary, so it is a misspelling
          printf("Misspelled word: ");
          for (k = 0; k < wordCount; k++) {
            printf("%c", text[i - wordCount + k]);
          }
          printf("\n");
          misspellings++;
        }
      }
      wordCount = 0;
    }
    else {
      wordCount++;
    }
  }

  if (misspellings == 0) {
    printf("No misspellings found!\n");
  }
  else {
    printf("Total misspellings: %d\n", misspellings);
  }

  return 0;
}