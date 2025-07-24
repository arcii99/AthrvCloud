//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10 // height of image in pixels
#define WIDTH 10 // width of image in pixels

// function to generate a random pixel color
char* generatePixelColor() {
  static char* colors[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
  int random = rand() % 15;
  return colors[random];
}

// function to print pixel art image
void printPixelArt(char pixelArt[HEIGHT][WIDTH][2]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%s ", pixelArt[i][j]);
    }
    printf("\n");
  }
}

int main() {
  char pixelArt[HEIGHT][WIDTH][2]; // initialize empty pixel art image
  srand(time(0)); // seed random generator
  
  // generate random pixel colors for each pixel in image
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      pixelArt[i][j][0] = generatePixelColor();
      pixelArt[i][j][1] = generatePixelColor();
    }
  }
  
  // print pixel art image
  printPixelArt(pixelArt);
  
  return 0;
}