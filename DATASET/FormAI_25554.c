//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ALIEN_CHARACTERS 10
#define MAX_TRANSLATION_LENGTH 50

int main() {

  // Alien language character array
  char alien_chars[NUM_ALIEN_CHARACTERS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
  
  // English language character array
  char english_chars[NUM_ALIEN_CHARACTERS] = {'X', 'Y', 'Z', 'Q', 'W', 'E', 'R', 'T', 'U', 'I'};

  printf("Welcome to the Alien Language Translator!\n\n");
  printf("Enter the alien text to translate (maximum of %d characters):\n", MAX_TRANSLATION_LENGTH);

  char alien_text[MAX_TRANSLATION_LENGTH + 1];
  fgets(alien_text, MAX_TRANSLATION_LENGTH + 1, stdin);

  // Translate the alien text to English
  int alien_text_length = strlen(alien_text);
  for (int i = 0; i < alien_text_length; i++) {
    char alien_char = alien_text[i];
    int alien_char_index = -1;

    // Find the index of the alien character in the alien_chars array
    for (int j = 0; j < NUM_ALIEN_CHARACTERS; j++) {
      if (alien_char == alien_chars[j]) {
        alien_char_index = j;
        break;
      }
    }

    // Translate or copy the character
    if (alien_char_index != -1) {
      alien_text[i] = english_chars[alien_char_index];
    }
    else {
      alien_text[i] = alien_char;
    }
  }

  printf("\nTranslated text:\n%s", alien_text);

  return 0;
}