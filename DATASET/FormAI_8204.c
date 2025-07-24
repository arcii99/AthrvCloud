//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
  // Open the input file
  FILE *fp;
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("Error: cannot open file '%s'\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  
  // Initialize variables and data structures
  char curr_word[MAX_WORD_LENGTH+1] = {'\0'};
  int freq_count[MAX_WORD_LENGTH+1] = {0};
  char curr_char;
  int curr_word_len = 0;

  // Traverse the file character by character
  while ((curr_char = fgetc(fp)) != EOF) {
    // If the current character is a letter or a digit, add it to the current word.
    if (isalnum(curr_char)) {
      curr_word[curr_word_len] = curr_char;
      curr_word_len++;
      if (curr_word_len > MAX_WORD_LENGTH) {
        printf("Error: maximum word length exceeded\n");
        exit(EXIT_FAILURE);
      }
    }
    // If the current character is not a letter or a digit, the current word is complete.
    else if (curr_word_len != 0) {
      // Convert the current word to lowercase
      for (int i = 0; i < curr_word_len; i++) {
        curr_word[i] = tolower(curr_word[i]);
      }
      // Increment the frequency count of the current word
      freq_count[curr_word_len]++;
      // Reset the current word and length for the next word
      memset(curr_word, '\0', sizeof curr_word);
      curr_word_len = 0;
    }
  }

  // Print the frequency counts
  for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
    if (freq_count[i] != 0) {
      printf("%d-letter words: %d\n", i, freq_count[i]);
    }
  }

  // Close the input file and exit
  fclose(fp);
  return 0;
}