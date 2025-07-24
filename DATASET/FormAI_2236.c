//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>

int main() {

  // Let's generate the random matrix
  int matrix[3][3];

  printf("Wooohooo! We're about to generate a random matrix!\n");

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      matrix[i][j] = rand() % 10;
    }
  }

  printf("Here's your random matrix:\n");

  // Let's print out the generated matrix
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Let's calculate the sum of the diagonal elements
  int diagonal_sum = 0;

  for(int i = 0; i < 3; i++) {
    diagonal_sum += matrix[i][i];
  }

  printf("The sum of diagonal elements is: %d\n", diagonal_sum);

  // Let's transpose the matrix
  printf("Alright, let's transpose the matrix now!\n");

  // Let's create a temporary matrix to store the transposed matrix
  int transposed[3][3];

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      transposed[i][j] = matrix[j][i];
    }
  }

  printf("Here's your transposed matrix:\n");

  // Let's print out the transposed matrix
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", transposed[i][j]);
    }
    printf("\n");
  }

  // Let's do some matrix multiplication
  int another_matrix[3][2] = {{1,2}, {3,4}, {5,6}};

  printf("Let's multiply two matrices now!\n");

  // Let's create a resultant matrix to store the result of multiplication
  int result[3][2];

  // Multiplying matrices
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 2; j++) {
      result[i][j] = 0;
      for(int k = 0; k < 3; k++) {
        result[i][j] += matrix[i][k] * another_matrix[k][j];
      }
    }
  }

  printf("Here's your multiplied matrix:\n");

  // Let's print out the multiplied matrix
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 2; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  
  printf("Wow, we're done with all matrix operations! That was fun!\n");
  
  return 0;
}