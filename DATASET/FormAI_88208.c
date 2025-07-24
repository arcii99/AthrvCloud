//FormAI DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#define ROW1 2
#define COL1 3
#define ROW2 3
#define COL2 2

int main() {
  int matrix1[ROW1][COL1] = {{1, 2, 3},
                             {4, 5, 6}};

  int matrix2[ROW2][COL2] = {{7, 8},
                             {9, 10},
                             {11, 12}};

  int result[ROW1][COL2] = {0};

  for(int i = 0; i < ROW1; i++) {
    for(int j = 0; j < COL2; j++) {
      for(int k = 0; k < ROW2; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  printf("The result matrix is:\n");
  for(int i = 0; i < ROW1; i++) {
    for(int j = 0; j < COL2; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}