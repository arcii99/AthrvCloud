//FormAI DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>

int main() {
  int matrix_a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7,8,9}};
  int matrix_b[3][3] = {{9, 8, 7}, {6, 5, 4}, {3,2,1}};
  int sum[3][3];

  // perform matrix addition
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
    }
  }

  printf("Matrix A:\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("%d ", matrix_a[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix B:\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("%d ", matrix_b[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix Sum:\n");
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      printf("%d ", sum[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}