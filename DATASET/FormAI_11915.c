//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to the C Cat Language Translator!\n");

  char translation[] = "Meow, I am a cat!";
  printf("Original phrase: %s\n", translation);

  // Translate "I am a cat" to "I am a C cat"
  translation[10] = 'C';
  printf("Translated phrase: %s\n", translation);

  // Add purring at the end
  translation[15] = ',';
  translation[16] = ' ';
  translation[17] = 'p';
  translation[18] = 'u';
  translation[19] = 'r';
  translation[20] = 'r';
  translation[21] = 'r';
  translation[22] = 'r';
  translation[23] = 'r';
  translation[24] = '\0';
  printf("Purrrred phrase: %s\n", translation);

  // Check if cat is hungry
  printf("Are you hungry, little C cat? (y/n)\n");

  char answer;
  scanf("%c", &answer);

  if (answer == 'y') {
    printf("Here's some yummy tuna!\n");
  } else if (answer == 'n') {
    printf("Maybe later then, take a nap!\n");
  } else {
    printf("I'm sorry, I don't understand.\n");
  }

  printf("Thanks for talking to me, little C cat!\n");
  return 0;
}