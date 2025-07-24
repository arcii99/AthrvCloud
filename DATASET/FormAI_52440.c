//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
#include <stdio.h>

void triangle(int size, int x, int y) { // Draws a triangle
  int line;
  for (line = 0; line < size; line++) {
    int i;
    for (i = 0; i <= line; i++) {
      printf(" ");
    }
    for (i = 0; i < (size - line); i++) {
      printf("* ");
    }
    printf("\n");
  }
}

void sierpinski(int size, int x, int y) { // Recursively generates Sierpinski Triangle
  if (size == 1) { // Base case, draw a single triangle
    triangle(size, x, y);
  } else { // Recursive case, split into three smaller triangles
    sierpinski(size / 2, x, y);
    sierpinski(size / 2, x + size / 2, y);
    sierpinski(size / 2, x + size / 4, y + size / 2);
  }
}

int main() {
  int size = 32;
  sierpinski(size, 0, 0);
  return 0;
}