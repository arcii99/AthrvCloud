//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <ctype.h>

// Define the maximum number of words that can be processed.
#define MAX_WORDS 1000

int main() {
  // Define an array to hold the words.
  char words[MAX_WORDS][100];

  // Define an array to hold the frequency counts.
  int freq[MAX_WORDS];

  // Define variables needed for processing input.
  char c, word[100];
  int i = 0, j = 0, k, count = 0;

  // Process input.
  while ((c = getchar()) != EOF) {
    // Only process alphabetic characters.
    if (isalpha(c)) {
      // Convert to lowercase.
      word[i++] = tolower(c);
    } else {
      // Null-terminate the word.
      word[i] = '\0';
      i = 0;

      // Check if the word is already in the array.
      for (k = 0; k < count; k++) {
        if (strcmp(words[k], word) == 0) {
          // Increment the count for this word.
          freq[k]++;
          break;
        }
      }

      // If the word is not already in the array, add it.
      if (k == count) {
        strcpy(words[count], word);
        freq[count] = 1;
        count++;
      }
    }
  }

  // Print the frequency counts.
  for (i = 0; i < count; i++) {
    printf("%s: %d\n", words[i], freq[i]);
  }

  return 0;
}