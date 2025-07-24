//FormAI DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, size;

  printf("Enter size of matrix: ");
  scanf("%d", &size);

  int **matrix = (int **)malloc(size * sizeof(int *));
  for (i = 0; i < size; i++) {
    matrix[i] = (int *)malloc(size * sizeof(int));
  }

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      matrix[i][j] = rand() % 100;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  int max = matrix[0][0];
  int min = matrix[0][0];

  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      if (matrix[i][j] > max) {
        max = matrix[i][j];
      }
      if (matrix[i][j] < min) {
        min = matrix[i][j];
      }
    }
  }

  printf("\nMaximum element in matrix: %d", max);
  printf("\nMinimum element in matrix: %d", min);

  for (i = 0; i < size; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}