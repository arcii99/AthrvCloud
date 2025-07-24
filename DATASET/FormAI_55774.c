//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int width, height;

  printf("Enter width of the canvas: "); //ask user for width of canvas
  scanf("%d", &width);

  printf("Enter height of the canvas: "); //ask user for height of canvas
  scanf("%d", &height);

  srand(time(NULL)); //initialize random seed

  //loop through each pixel of the canvas
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      int r = rand() % 256; //generate random red component (0-255)
      int g = rand() % 256; //generate random green component (0-255)
      int b = rand() % 256; //generate random blue component (0-255)

      //print the pixel in the format R,G,B with leading zeros if necessary
      printf("%03d,%03d,%03d ", r, g, b);
    }
    printf("\n"); //end the line after each row of pixels
  }

  return 0;
}