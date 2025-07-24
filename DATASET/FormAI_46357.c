//FormAI DATASET v1.0 Category: Matrix operations ; Style: medieval
#include <stdio.h>

int main() {
  // Greetings, Sir Knight. We shall begin by declaring our matrices.
  int matrix1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int matrix2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

  // Let us print out our matrices, as any good knight would inspect his tools.
  printf("Our matrices:\n"); 
  printf("Matrix 1:\n");
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      printf("%d ", matrix1[r][c]);
    }
    printf("\n");
  }
  printf("Matrix 2:\n");
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      printf("%d ", matrix2[r][c]);
    }
    printf("\n");
  }

  // We shall now perform a most noble task - adding the two matrices together.
  printf("\nAdding our matrices:\n");
  int sum_matrix[3][3];
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      sum_matrix[r][c] = matrix1[r][c] + matrix2[r][c];
      printf("%d ", sum_matrix[r][c]);
    }
    printf("\n");
  }

  // A most valiant task awaits us next - multiplying our matrices.
  printf("\nMultiplying our matrices:\n");
  int product_matrix[3][3];
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      product_matrix[r][c] = 0;
      for (int i = 0; i < 3; i++) {
        product_matrix[r][c] += matrix1[r][i] * matrix2[i][c];
      }
      printf("%d ", product_matrix[r][c]);
    }
    printf("\n");
  }

  // Our task is complete, Sir Knight. Let us part ways until we meet again.
  return 0;
}