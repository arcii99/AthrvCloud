//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the ASCII Art Generator!\n");
  printf("Please enter the character you want to use for your art: ");

  char c;
  scanf("%c", &c);

  printf("\nGreat choice! Let's get started:\n");

  printf("   ");
  for (int i = 0; i < 10; i++) {
    printf("%c ", c);
  }

  printf("\n");
  for (int i = 0; i < 9; i++) {
    printf("%c  ", c);
    for (int j = 0; j < 8; j++) {
      printf("--");
    }
    printf("%c\n", c);
  }

  printf(" ");
  for (int i = 0; i < 10; i++) {
    printf("%c ", c);
  }
  printf("\n\n");

  printf("Voila! Your masterpiece is complete.\n");
  printf("And remember, in ASCII art, there are no mistakes - only happy accidents.\n");

  return 0;
}