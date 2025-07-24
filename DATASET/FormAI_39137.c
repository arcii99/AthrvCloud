//FormAI DATASET v1.0 Category: Pattern printing ; Style: mind-bending
#include <stdio.h>

int main() {
  int x = 1, y = 1;
  char matrix[25][25];

  // Fill matrix with spaces.
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      matrix[i][j] = ' ';
    }
  }

  // Fill matrix with C pattern.
  for (int i = 1; i <= 10; i++) {
    matrix[x++][y++] = 'C';
  }

  for (int i = 1; i <= 10; i++) {
    matrix[x][y--] = 'C';
  }

  for (int i = 1; i <= 5; i++) {
    matrix[x++][y--] = 'C';
  }

  for (int i = 1; i <= 5; i++) {
    matrix[x++][y++] = 'C';
  }

  // Print matrix.
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 25; j++) {
      printf("%c ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}