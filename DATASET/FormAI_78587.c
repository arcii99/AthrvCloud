//FormAI DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>

int main() {
  int m, n, p, q;
  printf("Enter dimensions of Matrix A: ");
  scanf("%d %d", &m, &n);
  printf("Enter dimensions of Matrix B: ");
  scanf("%d %d", &p, &q);

  if (n != p) {
    printf("Error: Number of columns in Matrix A must equal number of rows in Matrix B");
    return 1;
  }

  int A[m][n], B[p][q], C[m][q];
  printf("Enter elements of Matrix A:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter elements of Matrix B:\n");
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < q; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      C[i][j] = 0;
      for (int k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  printf("The product of Matrix A and Matrix B is:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}