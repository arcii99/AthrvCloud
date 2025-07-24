//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int width = 10;
  int height = 10;

  int pixelArt[10][10] = 
  {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,1,1,0},
    {0,1,1,1,0,0,1,1,1,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,0,0,0},
    {0,0,0,0,1,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
  };

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (pixelArt[i][j] == 0) {
        printf(" ");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }

  return 0;
}