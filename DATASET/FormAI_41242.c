//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fractal(char array[][80], int x1, int y1, int x2, int y2) {
  
  int i, j, m, n, a, b;

  // Base case
  if (abs(x2 - x1) < 5 || abs(y2 - y1) < 5) {
    return;
  }

  // Draw a straight line
  if (x1 == x2) {
    for (i = y1; i <= y2; i++) {
      array[x1][i] = '*';
    }
    fractal(array, x1, y1, x1 + (y2 - y1) / 3, y2 - (y2 - y1) / 3);
    fractal(array, x1, y2 - (y2 - y1) / 3, x1 + (y2 - y1) / 3, y1 + (y2 - y1) / 3);
    fractal(array, x1 + (y2 - y1) / 3, y1, x2, y1 + (y2 - y1) / 3);
    fractal(array, x1 + (y2 - y1) / 3, y2 - (y2 - y1) / 3, x2, y2);
  }
  
  // Draw a diagonal line
  else {
    m = (y2 - y1) / (x2 - x1);
    n = y1 - m * x1;
    for (i = x1; i <= x2; i++) {
      j = m * i + n;
      array[i][j] = '*';
    }
    a = x1 + (x2 - x1) / 3;
    b = y1 + (y2 - y1) / 3;
    fractal(array, x1, y1, a, b);
    fractal(array, x1 + 2 * (x2 - x1) / 3, y1, x2, b);
    fractal(array, x1, y1 + 2 * (y2 - y1) / 3, a, y2);
    fractal(array, x1 + 2 * (x2 - x1) / 3, y1 + 2 * (y2 - y1) / 3, x2, y2);
  }
}

void print(char array[][80]) {
  
  int i, j;

  for (i = 0; i < 80; i++) {
    for (j = 0; j < 80; j++) {
      putchar(array[i][j]);
    }
    putchar('\n');
  }
}

int main() {
  
  char array[80][80];
  int i, j;

  for (i = 0; i < 80; i++) {
    for (j = 0; j < 80; j++) {
      array[i][j] = ' ';
    }
  }

  fractal(array, 0, 40, 80, 40);
  print(array);
  
  return 0;
}