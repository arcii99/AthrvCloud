//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: intelligent
#include <stdio.h>

/* This program generates pixel art in terminal using ASCII characters. */

int main(void) {
  char pixels[10][10];
  int i, j;

  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      if (i % 2 == 0) { /* Creates a checkerboard pattern */
        pixels[i][j] = (j % 2 == 0) ? '.' : 'o'; /* Change these characters to create different pixel art */
      } else {
        pixels[i][j] = (j % 2 == 0) ? 'o' : '.'; /* Change these characters to create different pixel art */
      }
    }
  }

  /* Print the generated pixel art */
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      printf("%c ", pixels[i][j]);
    }
    printf("\n");
  }

  return 0;
}