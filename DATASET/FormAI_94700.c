//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: automated
#include <stdio.h>

int main() {
  char catCode[100];
  printf("Enter the Cat Code to Translate: ");
  fgets(catCode, 100, stdin);

  printf("\nTranslating...\n\n");

  int i = 0;
  while (catCode[i] != '\0') {
    if (catCode[i] == 'm') {
      printf("Meow");
    } else if (catCode[i] == 'p') {
      printf("Purr");
    } else if (catCode[i] == 'h') {
      printf("Hiss");
    } else if (catCode[i] == 'y') {
      printf("Yowl");
    } else if (catCode[i] == 'c') {
      printf("Chirp");
    } else if (catCode[i] == 'r') {
      printf("Rawr");
    } else {
      printf("%c", catCode[i]);
    }

    i++;
  }

  return 0;
}