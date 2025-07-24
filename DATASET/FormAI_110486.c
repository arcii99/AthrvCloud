//FormAI DATASET v1.0 Category: Matrix operations ; Style: peaceful
#include <stdio.h>

int main() {
  int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int result[3][3];
  int i, j, k;

  // Matrix multiplication
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      result[i][j] = 0;
      for (k = 0; k < 3; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  // Matrix addition
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      result[i][j] += matrix1[i][j];
    }
  }

  // Print the multiplied and added matrix
  printf("Multiplied and added matrix:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}