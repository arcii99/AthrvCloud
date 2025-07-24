//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  srand(time(NULL)); // seed the random number generator
  
  char pixels[20][20]; // our 20x20 pixel grid
  int x, y; // x and y coordinates

  // loop through each pixel on the grid
  for (y=0; y<20; y++){
    for (x=0; x<20; x++){

      // generate a random number between 0 and 2
      int color = rand()%3;
      switch (color){

        // if the color is 0, set the pixel to red (R)
        case 0:
          pixels[y][x] = 'R';
          break;

        // if the color is 1, set the pixel to green (G)
        case 1:
          pixels[y][x] = 'G';
          break;

        // if the color is 2, set the pixel to blue (B)
        case 2:
          pixels[y][x] = 'B';
          break;
      }
    }
  }
  
  // print out the pixel grid
  printf("+--------------------+\n");
  for (y=0; y<20; y++){
    printf("|");
    for (x=0; x<20; x++){
      printf("%c", pixels[y][x]);
    }
    printf("|\n");
  }
  printf("+--------------------+\n");
  
  return 0; // we're done!
}