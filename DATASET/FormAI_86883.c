//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
  char alphabet[] = "C2DEFGHIJ4LMNOPQR57UVWXYZ";
  char input[256];
  int i, j;

  printf("Welcome to the C Alien Language Translator!\n");
  printf("Please enter the sentence you would like to translate:\n");
  fgets(input, sizeof(input), stdin);

  for (i = 0; i < strlen(input); i++) {
    if (input[i] == ' ') {
      printf(" ");
    } else {
      for (j = 0; j < strlen(alphabet); j++) {
        if (input[i] == alphabet[j]) {
          printf("%c", alphabet[strlen(alphabet) - 1 - j]);
        }
      }
    }
  }
  printf("\n");

  return 0;
}