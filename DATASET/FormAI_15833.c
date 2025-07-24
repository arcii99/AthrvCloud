//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// define the dimensions of the pixel art
#define HEIGHT 10
#define WIDTH 10

// array to hold the pixel art
int art[HEIGHT][WIDTH];

// function to generate random pixel art
void generate_art() {
  for (int row = 0; row < HEIGHT; row++) {
    for (int col = 0; col < WIDTH; col++) {
      // generate random pixel color
      int color = rand() % 2;
      // set pixel in array
      art[row][col] = color;
    }
  }
}

// function to print pixel art
void print_art() {
  for (int row = 0; row < HEIGHT; row++) {
    for (int col = 0; col < WIDTH; col++) {
      // print pixel character based on color
      if (art[row][col] == 0) {
        printf(" ");
      } else {
        printf("#");
      }
    }
    printf("\n");
  }
}

int main() {
  // set random seed
  srand(42);

  // generate and print pixel art
  generate_art();
  printf("Here is your pixel art:\n");
  print_art();

  return 0;
}