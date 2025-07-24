//FormAI DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>

int main() {
  int matrix[5][5];

  // Initializing the matrix with random numbers
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrix[i][j] = (i + j) * (i - j);
    }
  }

  // Printing the graph using the matrix
  printf("\n");
  printf("  ----- Graph -----  \n");
  for (int i = 0; i < 5; i++) {
    printf("  | ");
    for (int j = 0; j < 5; j++) {
      if (matrix[i][j] >= 0) {
        printf(" ");
      }
      printf("%d ", matrix[i][j]);
    }
    printf(" |\n");
  }
  printf("  ------------------  \n");

  return 0;
}