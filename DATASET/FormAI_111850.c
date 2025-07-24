//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: scientific
#include <stdio.h>
#include <string.h>

#define ALPHABET_LENGTH 26
#define MAX_WORD_LENGTH 30

// Declare the function to translate the alien language
void translate(char* word, char* translation);

int main() {
  // Define a dictionary for the alien language
  char dictionary[ALPHABET_LENGTH][MAX_WORD_LENGTH] = {
    "abev", "cdef", "ghij", "klmn",
    "opqr", "stuv", "wxyz",
  };

  // Get a word to translate from the user
  char input[MAX_WORD_LENGTH];
  printf("Enter a word in the alien language: ");
  scanf("%s", input);

  // Translate each letter in the word
  char output[MAX_WORD_LENGTH];
  int input_length = strlen(input);
  for (int i = 0; i < input_length; i++) {
    char letter = input[i];
    if (letter >= 'a' && letter <= 'z') { // If it's a letter
      int index = letter - 'a';
      translate(dictionary[index], output + i);
    } else { // Otherwise, just copy it over without translating
      output[i] = letter;
    }
  }

  // Print the translated word
  printf("Translation: %s", output);

  return 0;
}

void translate(char* word, char* translation) {
  // Translate the word by reversing it
  int length = strlen(word);
  for (int i = 0; i < length; i++) {
    translation[i] = word[length - i - 1];
  }
  translation[length] = '\0'; // Add the null-terminator
}