//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

// Function to initialize the matrix with random values
void initializeMatrix(int matrix[][WIDTH]) {
  int i, j;
  srand(time(NULL)); // seed random number generator
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      matrix[i][j] = rand() % 2; // generate either 0 or 1
    }
  }
}

// Function to print the matrix as pixel art
void printPixelArt(int matrix[][WIDTH]) {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      if (matrix[i][j] == 0) {
        printf(" "); // print a blank space for 0
      } else {
        printf("*"); // print a star for 1
      }
    }
    printf("\n"); // move to the next row
  }
}

int main() {
  int matrix[HEIGHT][WIDTH]; // declare the matrix
  initializeMatrix(matrix); // initialize it with random values
  printPixelArt(matrix); // print it as pixel art
  return 0;
}