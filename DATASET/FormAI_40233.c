//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: interoperable
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

//Function to generate a random color code for the pixel
void randomColor(char* color) { 
  srand(time(NULL)); //use current time as seed for random generator

  char* colors = "0123456789ABCDEF"; 
  int i; 

  for (i = 0; i < 6; i++) { 
    color[i] = colors[rand() % 16]; 
  } 
} 

int main() {
  int height, width;
  printf("Enter the height and width of the pixel art (separated by space):\n");
  scanf("%d %d", &height, &width);

  char pixel[height][width][7]; //3D array to store the color codes of each pixel
  int i, j, k;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      char color[7];
      randomColor(color);
      for (k = 0; k < 7; k++) {
        pixel[i][j][k] = color[k];
      }
    }
  }

  //Print the pixel art
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      printf("#%s ", pixel[i][j]);
    }
    printf("\n");
  }

  return 0;
}