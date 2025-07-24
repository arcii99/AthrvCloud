//FormAI DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 3
#define COLS 3

void transpose(double matrix[ROWS][COLS], double result[COLS][ROWS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      result[j][i] = matrix[i][j];
    }
  }
}

void multiply(double matrixA[ROWS][COLS], double matrixB[ROWS][COLS], double result[ROWS][COLS]) {
  int i,j,k;
  double sum;

  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < ROWS; j++) {
      sum = 0.0;
      for (k = 0; k < COLS; k++) {
        sum += matrixA[i][k] * matrixB[k][j];
      }
      result[i][j] = sum;
    }
  }
}

void printMatrix(double matrix[ROWS][COLS]) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%3.2f ", matrix[i][j]);
    }
    printf("\n");
  }
}

void dataMining(double data[ROWS][COLS]) {
  double covarianceMatrix[ROWS][ROWS];
  double centeredMatrix[ROWS][COLS];
  double transposeMatrix[COLS][ROWS];

  double avg[COLS] = {0};
  double variance[COLS] = {0};

  int i, j;

  // subtract column average from each value
  for (i = 0; i < COLS; i++) {
    for (j = 0; j < ROWS; j++) {
      avg[i] += data[j][i];
    }
    avg[i] /= ROWS;

    for (j = 0; j < ROWS; j++) {
      centeredMatrix[j][i] = data[j][i] - avg[i];
    }
  }

  // calculate variance of each column
  for (i = 0; i < COLS; i++) {
    for (j = 0; j < ROWS; j++) {
      variance[i] += pow(centeredMatrix[j][i], 2);
    }
    variance[i] /= ROWS;
  }

  // calculate covariance matrix
  transpose(centeredMatrix, transposeMatrix);
  multiply(centeredMatrix, transposeMatrix, covarianceMatrix);

  printf("Data:\n");
  printMatrix(data);
  printf("\n");

  printf("Centered Matrix:\n");
  printMatrix(centeredMatrix);
  printf("\n");

  printf("Covariance Matrix:\n");
  printMatrix(covarianceMatrix);
  printf("\n");

  printf("Column Average:\n");
  for (i = 0; i < COLS; i++) {
    printf("Column %d: %3.2f\n", i+1, avg[i]);
  }
  printf("\n");

  printf("Column Variance:\n");
  for (i = 0; i < COLS; i++) {
    printf("Column %d: %3.2f\n", i+1, variance[i]);
  }
}

int main() {
  double data[ROWS][COLS] = {
    {4.0, 1.0, 1.0},
    {1.0, 2.0, 3.0},
    {1.0, 3.0, 6.0}
  };

  dataMining(data);

  return 0;
}