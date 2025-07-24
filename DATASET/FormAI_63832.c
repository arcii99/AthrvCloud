//FormAI DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>

void printMatrix(int *arr, int rows, int cols) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d ", *(arr + i * cols + j));
    }
    printf("\n");
  }
}

void addMatrix(int *a, int *b, int *c, int rows, int cols) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      *(c + i * cols + j) = *(a + i * cols + j) + *(b + i * cols + j);
    }
  }
}

void subtractMatrix(int *a, int *b, int *c, int rows, int cols) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      *(c + i * cols + j) = *(a + i * cols + j) - *(b + i * cols + j);
    }
  }
}

void multiplyMatrix(int *a, int *b, int *c, int rows1, int cols1, int cols2) {
  int i, j, k;
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols2; j++) {
      *(c + i * cols2 + j) = 0;
      for (k = 0; k < cols1; k++) {
        *(c + i * cols2 + j) += *(a + i * cols1 + k) * *(b + k * cols2 + j);
      }
    }
  }
}

int main() {
  int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int b[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
  int c[3][3], d[3][3], e[3][3];

  addMatrix(&a[0][0], &b[0][0], &c[0][0], 3, 3);
  printf("Addition Result:\n");
  printMatrix(&c[0][0], 3, 3);

  subtractMatrix(&a[0][0], &b[0][0], &c[0][0], 3, 3);
  printf("Subtraction Result:\n");
  printMatrix(&c[0][0], 3, 3);

  multiplyMatrix(&a[0][0], &b[0][0], &c[0][0], 3, 3, 3);
  printf("Multiplication Result:\n");
  printMatrix(&c[0][0], 3, 3);
  
  transposeMatrix(&a[0][0], &d[0][0], 3, 3);
  printf("Transpose of A:\n");
  printMatrix(&d[0][0], 3, 3);
  
  // Computing the determinant of matrix A
  int deter = determinantOfMatrix(&a[0][0], 3);
  printf("Determinant of A = %d\n", deter);
  
  // Inverse of matrix A
  if (deter == 0) {
    printf("Inverse of A does not exist");
  } else {
    inverseOfMatrix(&a[0][0], &e[0][0], 3);
    printf("Inverse of A:\n");
    printMatrix(&e[0][0], 3, 3);
  }

  return 0;
}

int determinantOfMatrix(int *arr, int n) {
  int i, j, k, sign = 1, determinant = 0;
  int minorArr[(n - 1) * (n - 1)];
  if (n == 1) {
    return *arr;
  }
  for (i = 0; i < n; i++) {
    k = 0;
    for (j = n; j < n * n; j++) {
      if (j % n != i) {
        minorArr[k++] = *(arr + j);
      }
    }
    determinant += sign * *(arr + i) * determinantOfMatrix(minorArr, n - 1);
    sign = -sign;
  }
  return determinant;
}

void getCofactor(int *arr, int *temp, int n, int p, int q) {
  int i = 0, j = 0, row, col;
  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      if (row != p && col != q) {
        *(temp + i * (n - 1) + j) = *(arr + row * n + col);
        j++;
        if (j == n - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

void adjointOfMatrix(int *arr, int *adj, int n) {
  if (n == 1) {
    *adj = 1;
    return;
  }
  int sign = 1, temp[n - 1][n - 1];
  int i, j, k, l, *tempPtr;
  tempPtr = &temp[0][0];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      getCofactor(arr, tempPtr, n, i, j);
      sign = ((i + j) % 2 == 0) ? 1 : -1;
      *(adj + j * n + i) = sign * determinantOfMatrix(tempPtr, n - 1);
    }
  }
}

int inverseOfMatrix(int *arr, float *inv, int n) {
  int det, i, j, *adj, *temp;
  adj = (int *) malloc(n * n * sizeof(int));
  temp = (int *) malloc((n-1) * (n-1) * sizeof(int));
  adjointOfMatrix(arr, adj, n);
  det = determinantOfMatrix(arr, n);
  if (det == 0) {
    return 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      *(inv + i * n + j) = (float) *(adj + i * n + j) / det;
    }
  }
  free(adj);
  free(temp);
  return 1;
}

void transposeMatrix(int *arr, int *trans, int n, int m) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      *(trans + j * n + i) = *(arr + i * m + j);
    }
  }
}