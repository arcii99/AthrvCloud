//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <string.h>

/* This program is a C Alien Language Translator! */

int main() {
  char alien_word[20];
  char translation[20];

  printf("Welcome to the C Alien Language Translator!\n");
  printf("Please enter an alien word (up to 20 characters): ");
  scanf("%s", alien_word);

  if (strcmp(alien_word, "Blerg") == 0) {
    strcpy(translation, "Hello");
  } else if (strcmp(alien_word, "Zorp") == 0) {
    strcpy(translation, "Goodbye");
  } else if (strcmp(alien_word, "Flurp") == 0) {
    strcpy(translation, "Thank you");
  } else if (strcmp(alien_word, "Snickerdoodle") == 0) {
    strcpy(translation, "I love you");
  } else {
    strcpy(translation, "I'm sorry, I do not know that word in C Alien Language");
  }

  printf("The translation for %s is: %s\n", alien_word, translation);
  printf("Thank you for using the C Alien Language Translator! Have a great day!\n");

  return 0;
}