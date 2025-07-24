//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Hello, colorful C patterns!\n");

  int rows = 7;
  int cols = 20;
  char pattern[rows][cols];

  // Clear pattern array
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      pattern[i][j] = ' ';
    }
  }

  // Fill pattern array with a cheerful C pattern
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == 0 && j % 2 == 0) {
        pattern[i][j] = '*';
      }
      if (i == rows - 1 && j % 2 == 0) {
        pattern[i][j] = '*';
      }
      if ((i + j) % 4 == 0) {
        pattern[i][j] = '*';
      }
    }
  }

  // Print pattern array
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c ", pattern[i][j]);
    }
    printf("\n");
  }

  return 0;
}