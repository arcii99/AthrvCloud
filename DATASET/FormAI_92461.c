//FormAI DATASET v1.0 Category: Word Count Tool ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000 // maximum length for file input

int main(void) {
  char input[MAX_LENGTH]; // input buffer
  int total_words = 0; // counter for all words
  int unique_words = 0; // counter for unique words
  int c, i, current_word_length;
  char previous_char = ' ';
  char current_word[MAX_LENGTH];

  // Prompt user for file path and read input
  printf("Enter the file path: ");
  fgets(input, MAX_LENGTH, stdin);

  // Open file and read input
  FILE *file = fopen(input, "r");
  if (file != NULL) {
    while ((c = fgetc(file)) != EOF && total_words <= MAX_LENGTH) {
      if (isspace(previous_char) && !isspace(c)) {
        unique_words++; // new word found
        current_word_length = 0; // reset current word length
        for (i = 0; i < MAX_LENGTH; i++) {
          current_word[i] = '\0'; // reset current word
        }
      } 
      if (!isspace(c)) {
        current_word[current_word_length] = tolower(c);
        current_word_length++;
      }
      previous_char = c;
      total_words++; // increment total word count
    }
    fclose(file);
  } else {
    printf("Could not open file.\n");
    return 1;
  }

  printf("Total word count: %d\n", total_words);
  printf("Unique word count: %d\n", unique_words);

  return 0;
}