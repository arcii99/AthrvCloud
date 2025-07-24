//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //initialize random seed

  int height, width; //initialize variables to store input values
  printf("Enter the height and width of the pixel art: ");
  scanf("%d %d", &height, &width);

  char pixelArt[height][width]; //initialize 2D array to store pixel art

  //loop through each element of pixelArt and randomly assign '0' or '1'
  for(int row=0; row<height; row++) {
    for(int col=0; col<width; col++) {
      int randomNum = rand() % 2; //generate random number 0 or 1
      if(randomNum == 0) {
        pixelArt[row][col] = '0';
      } else {
        pixelArt[row][col] = '1';
      }
    }
  }

  //print out the generated pixel art
  printf("Generated Pixel Art:\n");
  for(int row=0; row<height; row++) {
    for(int col=0; col<width; col++) {
      printf("%c ", pixelArt[row][col]);
    }
    printf("\n"); //move to next line after each row
  }

  return 0; //end program
}