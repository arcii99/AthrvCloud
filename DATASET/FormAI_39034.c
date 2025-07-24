//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
  int i, j;

  char img[HEIGHT * WIDTH + 1];
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if ((i + j) % 2 == 0) {
        img[i * WIDTH + j] = '*';
      } else {
        img[i * WIDTH + j] = ' ';
      }
    }
  }
  img[HEIGHT * WIDTH] = '\0';

  for (i = 0; i < HEIGHT; i++) {
    printf("%.*s\n", WIDTH, &img[i * WIDTH]);
  }

  return EXIT_SUCCESS;
}