//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: automated
#include<stdio.h>

int main() {
  // Define the grid size
  int rows = 10;
  int columns = 10;
  // Define the characters to use for the pixel art
  char characters[2] = {' ', '+'};
  // Initialize the pixel grid
  int pixels[rows][columns];
  
  // Generate random pixel values
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      pixels[i][j] = rand() % 2;
    }
  }
  
  // Print the pixel art
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%c", characters[pixels[i][j]]);
    }
    printf("\n");
  }
  
  return 0;
}