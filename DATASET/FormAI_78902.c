//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

void print_matrix(int matrix[ROWS][COLS]);
void add_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);
void transpose_matrix(int matrix[ROWS][COLS], int result[ROWS][COLS]);
void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]);
void scalar_multiply(int matrix[ROWS][COLS], int scalar, int result[ROWS][COLS]);

int main() {
  int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int result[ROWS][COLS];

  printf("MATRIX OPERATIONS\n");
  printf("-----------------\n\n");

  printf("Matrix 1:\n");
  print_matrix(matrix1);

  printf("\nMatrix 2:\n");
  print_matrix(matrix2);

  printf("\nAddition:\n");
  add_matrices(matrix1, matrix2, result);
  print_matrix(result);

  printf("\nTranspose of Matrix 1:\n");
  transpose_matrix(matrix1, result);
  print_matrix(result);

  printf("\nMultiplication:\n");
  multiply_matrices(matrix1, matrix2, result);
  print_matrix(result);

  printf("\nScalar Multiplication of Matrix 2:\n");
  scalar_multiply(matrix2, 2, result);
  print_matrix(result);

  return 0;
}

void print_matrix(int matrix[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
}

void add_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

void transpose_matrix(int matrix[ROWS][COLS], int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = matrix[j][i];
    }
  }
}

void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = 0;
      for (int k = 0; k < COLS; k++) {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
}

void scalar_multiply(int matrix[ROWS][COLS], int scalar, int result[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      result[i][j] = matrix[i][j] * scalar;
    }
  }
}