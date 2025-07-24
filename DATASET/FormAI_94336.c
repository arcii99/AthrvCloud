//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, m;

  printf("Enter the dimensions of the matrix: ");
  scanf("%d %d", &n, &m);

  int matrix[n][m];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      matrix[i][j] = rand() % 10;
    }
  }

  printf("Original Matrix:\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Transpose the matrix
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < m; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  printf("Transposed Matrix:\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}