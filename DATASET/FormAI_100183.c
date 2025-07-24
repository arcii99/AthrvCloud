//FormAI DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input[256];

  printf("What is your name?\n");
  fgets(input, 256, stdin);
  strtok(input, "\n"); // remove new line character from input string

  printf("Hello, %s! How many fingers do you have?\n", input);
  fgets(input, 256, stdin);
  strtok(input, "\n");

  int fingers = atoi(input); // convert input string to integer

  if (fingers > 10) {
    printf("That's too many fingers!\n");
  } else if (fingers < 10) {
    printf("That's not enough fingers!\n");
  } else {
    printf("That's the correct number of fingers!\n");
  }

  return 0;
}