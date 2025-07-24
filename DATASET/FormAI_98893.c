//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: grateful
#include <stdio.h>

int main() {
  int pixelGrid[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,1,0},
    {1,1,0,0,0,1,1,1,1,0},
    {1,0,0,0,1,1,1,1,1,1},
    {0,0,0,0,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,1,1,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
  };
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (pixelGrid[i][j] == 1) {
        printf("█");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}