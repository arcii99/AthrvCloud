//FormAI DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if the word is spelled correctly
int check_spelling(char *word, char **dictionary, int dictionary_size) {
  for(int i=0; i<dictionary_size; i++) {
    if(strcmp(word, dictionary[i]) == 0) {
      return 1; // return 1 if the word is found in the dictionary
    }
  }
  return 0; // return 0 if the word is not found in the dictionary
}

// Function to sanitize the input word
void sanitize_word(char *word) {
  int len = strlen(word);
  for(int i=0; i<len; i++) {
    word[i] = tolower(word[i]); // convert all characters to lowercase
    if(!isalpha(word[i])) {
      for(int j=i; j<len-1; j++) {
        word[j] = word[j+1]; // remove any non-alphabetic characters
      }
      word[len-1] = '\0'; // add null character at the end of the word
      len--; // update length of the word
      i--; // update index of the current character being checked
    }
  }
}

// Main function
int main() {
  // Sample dictionary of words
  char *dictionary[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "orange", "papaya", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "zucchini"};
  int dictionary_size = sizeof(dictionary)/sizeof(dictionary[0]);

  // Get input from user
  char input[100];
  printf("Enter a word: ");
  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0'; // remove trailing newline character

  // Sanitize the input word
  sanitize_word(input);

  // Check the spelling of the input word
  int is_spelled_correctly = check_spelling(input, dictionary, dictionary_size);

  // Output the result
  if(is_spelled_correctly) {
    printf("The word \"%s\" is spelled correctly.\n", input);
  }
  else {
    printf("The word \"%s\" is spelled incorrectly.\n", input);
  }

  return 0;
}