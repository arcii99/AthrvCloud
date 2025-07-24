//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <string.h>

// Declare an array of strings to hold the cat language words
const char* cat_words[] = {"meow", "purr", "scratch", "biscuit", "mouse"};

// Declare an array of strings to hold the English words
const char* english_words[] = {"hello", "happy", "angry", "food", "enemy"};

// Declare a function to translate a single word
void translate_word(char* word) {

  int i;
  int found = 0;

  // Search for the word in the array of cat words
  for (i = 0; i < 5; i++) {
    if (strcmp(word, cat_words[i]) == 0) {
      found = 1;
      break;
    }
  }

  // Translate the word if it was found
  if (found) {
    printf("%s ", english_words[i]);
  } else {
    printf("%s ", word);
  }
}

int main() {

  int c;
  char word[20];
  int count = 0;

  // Read words from input until end of file
  while ((c = getchar()) != EOF) {

    // Check if the character is a letter or an apostrophe
    if (isalpha(c) || c == '\'') {

      // Add the character to the current word
      word[count] = c;
      count++;

      // Check if the word is too long
      if (count >= 20) {
        printf("ERROR: word too long\n");
        return 1;
      }

    } else {

      // Null-terminate the current word
      word[count] = '\0';
      count = 0;

      // Translate the word
      translate_word(word);

      // Print non-letter characters
      putchar(c);
    }

  }

  return 0;
}