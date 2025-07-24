//FormAI DATASET v1.0 Category: Fractal Generation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {

  int rows,cols, i, j, k, m, x, y;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  printf("\nEnter the number of columns: ");
  scanf("%d", &cols);

  int **fractal;

  fractal = (int **)malloc(sizeof(int *) * rows);
  for(i = 0; i < rows; i++)
    fractal[i] = (int *)malloc(sizeof(int) * cols);

  for(i = 0; i < rows; i++)
    for(j = 0; j < cols; j++)
      fractal[i][j] = 0;

  fractal[rows / 2][cols / 2] = 1;

  for(k = 1; k < (rows > cols ? (rows / 2) + 1 : (cols / 2) + 1); k++) {
    for(i = k; i < rows - k; i++) {
      for(j = k; j < cols - k; j++) {
        if((fractal[i - k][j] == 1 || fractal[i + k][j] == 1) || (fractal[i][j - k] == 1 || fractal[i][j + k] == 1)) {
          fractal[i][j] = 1;
        }
      }
    }
  }

  for(i = 0; i < rows; i++) {
    for(j = 0; j < cols; j++) {
      printf("%d ", fractal[i][j]);
    }
    printf("\n");
  }

  return 0;
}