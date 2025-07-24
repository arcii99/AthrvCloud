//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>

// Recursive function to determine points of a fractal square
void fractalSquare(int x, int y, int size, int level) {
  // Base case
  if (level == 0) {
    printf("%d %d\n", x, y);
    return;
  }

  // Recursive case
  int halfSize = size / 2;
  fractalSquare(x - halfSize, y - halfSize, halfSize, level - 1);
  fractalSquare(x + halfSize, y - halfSize, halfSize, level - 1);
  fractalSquare(x + halfSize, y + halfSize, halfSize, level - 1);
  fractalSquare(x - halfSize, y + halfSize, halfSize, level - 1);
}

// Function to draw a fractal square
void drawFractalSquare(int x, int y, int size, int level) {
  // Draw initial square
  printf("%d %d\n", x - size / 2, y - size / 2);
  printf("%d %d\n", x + size / 2, y - size / 2);
  printf("%d %d\n", x + size / 2, y + size / 2);
  printf("%d %d\n", x - size / 2, y + size / 2);
  
  // Determine points of fractal squares
  fractalSquare(x, y, size, level);
}

int main() {
  // Draw fractal square of size 200 at coordinate (300, 300) with level 4
  drawFractalSquare(300, 300, 200, 4);
  
  return 0;
}