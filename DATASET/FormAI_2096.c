//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  char pixels[10][10];

  for (int i = 0; i < 10; i++) {   // generate random pixel art
    for (int j = 0; j < 10; j++) {
      int rand_num = rand() % 2;  // 50% chance of a pixel being filled
      if (rand_num == 0) {
        pixels[i][j] = ' ';
      } else {
        pixels[i][j] = 'x';
      }
    }
  }

  printf(" ____________________________________\n");
  printf("|                                    |\n");

  for (int i = 0; i < 10; i++) {   // output pixel art
    printf("|");
    for (int j = 0; j < 10; j++) {
      printf(" %c", pixels[i][j]);
    }
    printf(" |\n");
  }

  printf("|____________________________________|\n");

  return 0;
}