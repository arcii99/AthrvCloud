//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePixel(int size, int row, int col) {
  if (size == 1) {
    printf("C");
    return;
  }

  int c = rand() % 2;
  if (c == 0) {
    generatePixel(size/2, row, col);
    generatePixel(size/2, row + size/2, col + size/2);
  }
  else {
    generatePixel(size/2, row, col + size/2);
    generatePixel(size/2, row + size/2, col);
  }
}

int main() {
  srand(time(NULL));
  
  int size, row, col;
  
  printf("Please input the size of the pixel art (must be a power of 2): ");
  scanf("%d", &size);

  printf("Please input the row and col coordinates of the top-left corner of the pixel art: ");
  scanf("%d%d", &row, &col);

  if (size <= 0 || row < 0 || col < 0) {
    printf("Invalid input.\n");
    return 0;
  }

  for (int i = row; i < row + size; i++) {
    for (int j = col; j < col + size; j++) {
      generatePixel(size, row, col);
    }
    printf("\n");
  }

  return 0;
}