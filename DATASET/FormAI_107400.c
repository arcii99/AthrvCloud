//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>

// This is a simple program that takes user input to draw a retro-style square.
// The square is filled with alternating diagonal lines to give a geometric effect.

int main() {
  int size;
  printf("Please enter the size of your square (1-10): ");
  scanf("%d", &size);

  // Error checking to make sure size is within range
  if (size < 1 || size > 10) {
    printf("Invalid size entered. Please enter a size between 1 and 10.\n");
    return 0;
  }

  // Loop through rows of the square
  for (int i = 0; i < size; i++) {
    // Loop through columns of the square
    for (int j = 0; j < size; j++) {
      // If the row and column are both even or odd, print an X
      if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
        printf("X");
      } else { // Otherwise, print a diagonal line
        printf("\\/");
      }
    }
    printf("\n"); // Move to the next row of the square
  }

  return 0;
}