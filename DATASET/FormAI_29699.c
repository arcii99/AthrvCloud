//FormAI DATASET v1.0 Category: Matrix operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

void add_matrices(int A[][COL], int B[][COL], int C[][COL]) {
  int i, j;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

void subtract_matrices(int A[][COL], int B[][COL], int C[][COL]) {
  int i, j;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
}

void multiply_matrices(int A[][COL], int B[][COL], int C[][COL]) {
  int i, j, k;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      C[i][j] = 0;
      for (k = 0; k < COL; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

void display_matrix(int mat[][COL]) {
  int i, j;
  for (i = 0; i < ROW; i++) {
    for (j = 0; j < COL; j++) {
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int A[ROW][COL] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int B[ROW][COL] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int C[ROW][COL];

  printf("Matrix A:\n");
  display_matrix(A);

  printf("\nMatrix B:\n");
  display_matrix(B);

  add_matrices(A, B, C);
  printf("\nA + B =\n");
  display_matrix(C);

  subtract_matrices(A, B, C);
  printf("\nA - B =\n");
  display_matrix(C);

  multiply_matrices(A, B, C);
  printf("\nA * B =\n");
  display_matrix(C);

  return 0;
}