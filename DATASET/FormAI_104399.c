//FormAI DATASET v1.0 Category: Pattern printing ; Style: enthusiastic
#include <stdio.h>

int main() {
  printf("Get ready to be amazed by this unique C pattern printing program!\n\n");
  
  // height and width of the pattern
  int height = 9;
  int width = 17;
  
  // loop to print the pattern
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if ((i == 0 && j >= width/2 - 2 && j <= width/2 + 2) || (i == height/2 && j >= width/2 - 6 && j <= width/2 + 6) || (i == height - 1 && j >= width/2 - 7 && j <= width/2 + 7) || (j == width/2 - 7 && i >= height/2 && i <= height - 2) || (j == width/2 + 7 && i >= 1 && i <= height/2) || ((i == 1 || i == height/2 - 1) && j == width/2 - 4) || ((i == 2 || i == height/2 - 2) && j == width/2 - 5) || ((i == height - 2 || i == height/2 + 1) && j == width/2 + 4) || ((i == height - 3 || i == height/2 + 2) && j == width/2 + 5) ) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  printf("\nImpressive, right? I'm just getting started!\n\n");
  
  // height and width of the pattern
  height = 13;
  width = 27;

  // loop to print the pattern
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if ((i == 0 && j >= width/2 - 3 && j <= width/2 + 3) || (i == height - 1 && j >= width/2 - 8 && j <= width/2 + 8) || ((i >= 1 && i <= height/2 - 1) && j == width/2 - 3) || ((i >= 1 && i <= height/2 - 1) && j == width/2 + 3) || ((i >= height/2 + 1 && i <= height - 2) && j == width/2 - 8) || ((i >= height/2 + 1 && i <= height - 2) && j == width/2 + 8) || ((i == height/2) && j >= width/2 - 7 && j <= width/2 + 7) || ((i == height/2 + 1 || i == height/2 - 1) && j >= width/2 - 6 && j <= width/2 + 6) ) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  printf("\nI hope you enjoyed my patterns! Come back soon for more amazing code!\n");
  
  return 0;
}