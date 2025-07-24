//FormAI DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100

int main() {
  char c, chars[MAX_WORDS];
  int count, words_len[MAX_WORDS], i, j, total = 0;
  bool in_word = false;
  
  printf("Enter a sentence: ");

  // Get input and calculate word lengths
  for(i = 0, count = 0; (c = getchar()) != '\n';) {
    if (isalpha(c)) {
      if (!in_word) {
        in_word = true;
        // Start a new word, begin its length count
        words_len[count] = 0;
      }

      // Store each character in char array and increment word length counter
      chars[i] = c;
      i++;
      words_len[count]++;
    } else if (in_word) {
      // End of a word, increment counter and reset flag for next word
      in_word = false;
      count++;
    }
  }

  // Output unique word lengths
  printf("\nTotal words: %d\n\n", count);

  for(i = 0; i < count; i++) {
    for(j = 0; j < i; j++) {
      if(words_len[i] == words_len[j]) {
        // The length of word 'i' matches word 'j', so skip counting 'i'
        break;
      }
    }

    if(i == j) {
      // Word 'i' has not been counted yet
      printf("%d letter word%c: %d\n", words_len[i], words_len[i] == 1 ? ' ' : 's', countWords(words_len[i], chars, count));
      total++;
    }
  }

  printf("\nTotal unique word lengths: %d", total);
  
  return 0;
}

// Function for counting words of a specific length
int countWords(int length, char* chars, int count) {
  int i, j, total = 0;
  bool match;

  // Iterate through each word, checking if length matches and incrementing total if so
  for(i = 0; i < count; i++) {
    match = true;

    for(j = 0; j < length; j++) {
      if(chars[i+j] == '\0' || !isalpha(chars[i+j])) {
        // Word ended early, so length does not match
        match = false;
        break;
      }
    }

    if(match && chars[i+j] == '\0') {
      // Word length matches and did not end early, so increment total count
      total++;
    }
  }

  return total;
}