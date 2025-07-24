//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  char alien_word[100];
  char english_word[100];

  printf("Welcome to the C Alien Language Translator!\n");
  printf("Please input an alien word you wish to translate: ");
  scanf("%s", alien_word);

  // Here, we will create a set of rules for translating the alien language to English
  if (strcmp(alien_word, "kluke") == 0) {
    strcpy(english_word, "hello");
  } else if (strcmp(alien_word, "plurn") == 0) {
    strcpy(english_word, "goodbye");
  } else if (strcmp(alien_word, "froop") == 0) {
    strcpy(english_word, "thank you");
  } else if (strcmp(alien_word, "snork") == 0) {
    strcpy(english_word, "please");
  } else {
    printf("Sorry, I did not recognize that word.\n");
    return 0;
  }

  printf("The translation of '%s' is '%s'\n", alien_word, english_word);
  printf("Thank you for using the C Alien Language Translator!\n");

  return 0;
}