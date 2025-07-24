//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  printf("Enter alien language: ");
  gets(input);

  if (strlen(input) == 0) {
    printf("Error: No input detected\n");
    return 0;
  }

  printf("Translation: ");

  int i;
  for (i = 0; i < strlen(input); i++) {
    char c = input[i];

    // Randomly generate translated character
    // This simulates the lack of understanding of the alien language
    int translated = c + (rand() % 10) - 5;

    // Ensure translated character is within the ASCII range of printable characters
    if (translated < 32) {
      translated += 10;
    } else if (translated >= 127) {
      translated -= 10;
    }

    putchar(translated);
  }

  printf("\n");
  return 0;
}