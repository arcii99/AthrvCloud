//FormAI DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
  int matrix[3][3] = {{1,2,3},
                      {4,5,6},
                      {7,8,9}};
  int row_sum[3] = {0};
  int col_sum[3] = {0};
  int diag_sum = 0;

  // Summing rows and columns
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      row_sum[i] += matrix[i][j];
      col_sum[j] += matrix[i][j];
    }
  }

  // Summing diagonal
  for (int i = 0; i < 3; i++) {
    diag_sum += matrix[i][i];
  }

  printf("Matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  printf("Sum of rows:\n");
  for (int i = 0; i < 3; i++) {
    printf("Row %d: %d\n", i+1, row_sum[i]);
  }

  printf("\n");

  printf("Sum of columns:\n");
  for (int i = 0; i < 3; i++) {
    printf("Column %d: %d\n", i+1, col_sum[i]);
  }

  printf("\n");

  printf("Sum of diagonal: %d\n", diag_sum);

  printf("\n");

  printf("What?! The matrix operations worked perfectly? This is unbelievable! I was expecting errors and bugs, but everything seems to be working fine.\n");

  return 0;
}