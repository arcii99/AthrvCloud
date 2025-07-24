//FormAI DATASET v1.0 Category: Matrix operations ; Style: innovative
#include <stdio.h>

int main() {
  int m, n;
  printf("Enter the dimensions of the matrix: ");
  scanf("%d %d", &m, &n);
  
  int matrix[m][n];
  
  printf("Enter the elements of the matrix:\n");
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  
  printf("The matrix you entered is:\n");
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  // Row sum
  int row_sum[m];
  for(int i=0; i<m; i++) {
    row_sum[i] = 0;
    for(int j=0; j<n; j++) {
      row_sum[i] += matrix[i][j];
    }
    printf("Sum of row %d = %d\n", i+1, row_sum[i]);
  }
  
  // Column sum
  int col_sum[n];
  for(int j=0; j<n; j++) {
    col_sum[j] = 0;
    for(int i=0; i<m; i++) {
      col_sum[j] += matrix[i][j];
    }
    printf("Sum of column %d = %d\n", j+1, col_sum[j]);
  }
  
  // Diagonal sum
  int diag_sum1 = 0, diag_sum2 = 0;
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      if(i == j) {
        diag_sum1 += matrix[i][j];
      }
      if(i+j == m-1) {
        diag_sum2 += matrix[i][j];
      }
    }
  }
  printf("Sum of diagonal 1 = %d\n", diag_sum1);
  printf("Sum of diagonal 2 = %d\n", diag_sum2);
  
  // Transpose of the matrix
  int transpose[n][m];
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      transpose[j][i] = matrix[i][j];
    }
  }
  
  printf("The transpose of the matrix is:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}