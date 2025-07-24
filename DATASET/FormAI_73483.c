//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the width and height of the canvas
#define WIDTH 10
#define HEIGHT 10

// Define the size of each pixel
#define PIXEL_SIZE 2

// Define the number of colors
#define NUM_COLORS 8

// Define the characters that represent each color
char colors[NUM_COLORS] = {' ', '.', ':', '*', 'o', '&', '8', '#'};

// Generate a random pixel art by assigning a color to each pixel
void generatePixelArt(char canvas[WIDTH][HEIGHT]){
  int i, j, color;
  
  // Loop over each pixel and assign a random color
  for(i = 0; i < WIDTH; i++){
    for(j = 0; j < HEIGHT; j++){
      
      // Generate a random color index
      color = rand() % NUM_COLORS;
      
      // Set the color of the current pixel
      canvas[i][j] = colors[color];
    }
  }
}

// Print the pixel art on the console
void printPixelArt(char canvas[WIDTH][HEIGHT]){
  int i, j, x, y;
  
  for(i = 0; i < WIDTH; i++){
    for(x = 0; x < PIXEL_SIZE; x++){
      
      // Print each row of pixels
      for(j = 0; j < HEIGHT; j++){
        for(y = 0; y < PIXEL_SIZE; y++){
          printf("%c", canvas[i][j]);
        }
      }
      
      // Move to the next row of pixels
      printf("\n");
    }
  }
}

// Main function
int main(){
  char canvas[WIDTH][HEIGHT];
  srand(time(0));
  
  // Generate a random pixel art
  generatePixelArt(canvas);
  
  // Print the pixel art on the console
  printPixelArt(canvas);
  
  return 0;
}