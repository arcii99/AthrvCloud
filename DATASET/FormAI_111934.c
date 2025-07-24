//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: visionary
#include <stdio.h> 

int main() {
  int i, j, side, space;

  printf("Enter the side of the square: "); // User input side of the square
  scanf("%d", &side);

  if (side <= 0) { // Check if the user input is valid
    printf("Invalid input!\n");
    return 0;
  }

  for (i = 1; i <= side; i++) {
    for (j = 1; j <= side; j++) {
      if (i == 1 || i == side || j == 1 || j == side) { // Print asterisk for the corners and edges
        printf("*");
      } else if (i == j || i == (side - j + 1)) { // Print asterisk for the diagonal lines
        printf("*");
      } else { // Print space for the inner square
        printf(" ");
      }
    }
    printf("\n"); // New line after each row
  }

  return 0;
}