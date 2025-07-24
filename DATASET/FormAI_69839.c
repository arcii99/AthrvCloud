//FormAI DATASET v1.0 Category: Fractal Generation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

// Set the desired size of the fractal
#define SIZE 1000

int fractal[SIZE][SIZE];

void generateFractal(int x1, int x2, int y1, int y2, int depth) {

  // Base case: if depth is 0, fill the rectangle with a color
  if (depth == 0) {
    int color = rand() % 256;
    for (int i = x1; i < x2; i++) {
      for (int j = y1; j < y2; j++) {
        fractal[i][j] = color;
      }
    }
  } else {
    // Otherwise, split the rectangle into four pieces and recurse on them
    int xm = (x1 + x2) / 2;
    int ym = (y1 + y2) / 2;

    generateFractal(x1, xm, y1, ym, depth - 1);
    generateFractal(xm, x2, y1, ym, depth - 1);
    generateFractal(x1, xm, ym, y2, depth - 1);
    generateFractal(xm, x2, ym, y2, depth - 1);
  }
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the fractal
  generateFractal(0, SIZE, 0, SIZE, 7);

  // Output the fractal as a PGM image file
  FILE* fp = fopen("fractal.pgm", "wb");
  fprintf(fp, "P5\n%d %d\n255\n", SIZE, SIZE);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      fputc(fractal[i][j], fp);
    }
  }
  fclose(fp);

  return 0;
}