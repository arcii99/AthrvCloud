//FormAI DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>
#define ROW 3
#define COL 3

int main() {
  int matrix[ROW][COL];
  int i, j, determinant;
  printf("Enter the elements of 3 x 3 matrix:\n");


  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      printf("Enter element a[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("The matrix is:\n");

  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  //Calculate determinant
  determinant = matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1])
               - matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[1][2]*matrix[2][0])
               + matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[1][1]*matrix[2][0]);

  printf("\nThe determinant of the matrix is %d.\n", determinant);

  return 0;
}