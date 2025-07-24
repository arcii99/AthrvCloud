//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
  char alien_word[20];
  printf("Welcome to the Alien Language Translator!\n");
  printf("Please enter an alien word: ");

  scanf("%s", alien_word);
  
  if (strcmp(alien_word, "greetings") == 0) {
    printf("Translation: Hello, how are you?\n");
  } else if (strcmp(alien_word, "food") == 0) {
    printf("Translation: I am hungry, please bring me sustenance.\n");
  } else if (strcmp(alien_word, "water") == 0) {
    printf("Translation: I am thirsty, please bring me hydration.\n");
  } else if (strcmp(alien_word, "home") == 0) {
    printf("Translation: Please take me to my dwelling.\n");
  } else if (strcmp(alien_word, "love") == 0) {
    printf("Translation: I feel warmth and happiness towards you.\n");
  } else {
    printf("Translation: I do not understand this word.\n");
  }

  return 0;
}