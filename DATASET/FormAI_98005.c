//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
  
  int width, height, i, j, randomColor;
  
  //Taking Input for Width and Height of Image
  
  printf("Enter the Width of the Image: ");
  scanf("%d", &width);
  
  printf("Enter the Height of the Image: ");
  scanf("%d", &height);
  
  //Generating Random Pixel Art
  
  srand(time(NULL));
  
  for(i=0; i<height; i++){
    for(j=0; j<width; j++){
      randomColor = rand() % 8 + 30; //Setting color pixel from 30 to 37
      printf("\033[48;5;%dm  ", randomColor); //Printing Colored Pixel
    }
    printf("\033[0m\n"); //Resetting the Color to Default
  }
  
}