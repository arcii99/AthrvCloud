//FormAI DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
  // Declare variables
  int matrix[ROWS][COLS];
  int scalar;
  int choice;

  // Prompt user to enter matrix elements
  printf("Enter %d elements of a %dx%d matrix: \n", ROWS*COLS, ROWS, COLS);
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  // Prompt user to select an operation
  printf("Select an operation to perform:\n");
  printf("1. Scalar multiplication\n");
  printf("2. Matrix addition\n");
  printf("3. Matrix subtraction\n");
  printf("4. Matrix multiplication\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      // Prompt user to enter scalar value
      printf("Enter a scalar value: ");
      scanf("%d", &scalar);

      // Multiply matrix by scalar
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          matrix[i][j] *= scalar;
        }
      }

      // Print result
      printf("Result of scalar multiplication:\n");
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          printf("%d ", matrix[i][j]);
        }
        printf("\n");
      }
      break;

    case 2:
      // Declare second matrix
      int matrix2[ROWS][COLS];

      // Prompt user to enter second matrix
      printf("Enter %d elements of a second %dx%d matrix: \n", ROWS*COLS, ROWS, COLS);
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          scanf("%d", &matrix2[i][j]);
        }
      }

      // Add matrices
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          matrix[i][j] += matrix2[i][j];
        }
      }

      // Print result
      printf("Result of matrix addition:\n");
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          printf("%d ", matrix[i][j]);
        }
        printf("\n");
      }
      break;

    case 3:
      // Declare second matrix
      int matrix3[ROWS][COLS];

      // Prompt user to enter second matrix
      printf("Enter %d elements of a second %dx%d matrix: \n", ROWS*COLS, ROWS, COLS);
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          scanf("%d", &matrix3[i][j]);
        }
      }

      // Subtract matrices
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          matrix[i][j] -= matrix3[i][j];
        }
      }

      // Print result
      printf("Result of matrix subtraction:\n");
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          printf("%d ", matrix[i][j]);
        }
        printf("\n");
      }
      break;

    case 4:
      // Declare second matrix
      int matrix4[COLS][ROWS];

      // Prompt user to enter second matrix
      printf("Enter %d elements of a %dx%d matrix: \n", ROWS*COLS, COLS, ROWS);
      for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
          scanf("%d", &matrix4[i][j]);
        }
      }

      // Multiply matrices
      int result[ROWS][ROWS];
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
          result[i][j] = 0;
          for (int k = 0; k < COLS; k++) {
            result[i][j] += matrix[i][k] * matrix4[k][j];
          }
        }
      }

      // Print result
      printf("Result of matrix multiplication:\n");
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < ROWS; j++) {
          printf("%d ", result[i][j]);
        }
        printf("\n");
      }
      break;

    default:
      printf("Invalid input.\n");
      break;
  }

  return 0;
}