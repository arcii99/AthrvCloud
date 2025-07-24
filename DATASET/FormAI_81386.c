//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* This program takes in a text input and returns the frequency of each character in the input. */

int main() {
  char input[1000];
  int charCount[127] = {0};
  int i, j;
  printf("Please input a string: ");
  fgets(input, 1000, stdin);
  for (i = 0; i < strlen(input); i++) {
    if (isalpha(input[i])) {
      charCount[toupper(input[i])]++;
    } else {
      charCount[input[i]]++;
    }
  }
  printf("Character frequency breakdown:\n");
  printf("-------------------------------\n");
  for (j = 65; j < 91; j++) {
    if (charCount[j] > 0) {
      printf("%c: %d\n", j, charCount[j]);
    }
  }
  printf("\n");
  for (j = 97; j < 123; j++) {
    if (charCount[j] > 0) {
      printf("%c: %d\n", j, charCount[j]);
    }
  }
  printf("\n");
  for (j = 33; j < 48; j++) {
    if (charCount[j] > 0) {
      printf("%c: %d\n", j, charCount[j]);
    }
  }
  printf("\n");
  for (j = 58; j < 65; j++) {
    if (charCount[j] > 0) {
      printf("%c: %d\n", j, charCount[j]);
    }
  }
  printf("\n");
  printf("Whitespace: %d\n", charCount[32]);
  return 0;
}