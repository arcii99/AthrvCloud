//FormAI DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>

int main() {
  printf("Oh my goodness! I can't believe this code is working!\n");
  
  int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  
  // Printing original matrix
  printf("\nOriginal Matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  printf("\nI hope you're sitting down, because I'm about to transpose this matrix...\n");

  // Transposing the matrix
  int temp;
  for (int i = 0; i < 3; i++) {
    for (int j = i; j < 3; j++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }
  
  printf("\nHoly smokes, it actually worked! Here's the transposed matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  printf("\nAnd just for kicks, let's multiply each element in the matrix by 2...\n");

  // Multiplying each element in the matrix by 2
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] *= 2;
    }
  }
  
  printf("\nThis is insane... it actually worked again! Here's the final matrix:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  
  printf("\nI'm not very good at expressing emotion, but that was a wild ride. Thanks for experiencing it with me!\n");
  
  return 0;
}