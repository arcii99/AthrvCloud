//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>

void printMatrix(int rows, int columns, int matrix[rows][columns]) {
  printf("\n");
  for(int x = 0; x < rows; x++) {
    for(int y = 0; y < columns; y++) {
      printf("%3d ", matrix[x][y]);
    }
    printf("\n");
  }
}

int main() {
  int matrix[2][2] = {{2, 3}, {4, 5}};
  int second_matrix[2][2] = {{1, 0}, {0, 1}};
  int result_matrix[2][2];
  
  printf("I am a matrix operations program and I'm ready to chop some matrices!\n");
  printf("This is your starting matrix:\n");
  printMatrix(2, 2, matrix);
  printf("This is the second matrix we'll use:\n");
  printMatrix(2, 2, second_matrix);

  printf("I will now add the two matrices together, brace yourself...\n");
  for(int x = 0; x < 2; x++) {
    for(int y = 0; y < 2; y++) {
      result_matrix[x][y] = matrix[x][y] + second_matrix[x][y];
    }
  }
  printf("POW! The result is:\n");
  printMatrix(2, 2, result_matrix);

  printf("Now, I will multiply the two matrices. This one's gonna be exciting!\n");
  for(int x = 0; x < 2; x++) {
    for(int y = 0; y < 2; y++) {
      result_matrix[x][y] = matrix[x][0] * second_matrix[0][y] + matrix[x][1] * second_matrix[1][y];
    }
  }
  printf("Big moment... READY? Here's the result:\n");
  printMatrix(2, 2, result_matrix);

  printf("And there you have it folks, my impressive matrix skills. Tune in next time for more matrix madness!\n");

  return 0;
}