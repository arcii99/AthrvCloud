//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome to the Matrix
  int matrix[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
  printf("Welcome to the Matrix.\n\n");

  // Let's manipulate the Matrix
  printf("The original Matrix is:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Let's multiply the Matrix by 2
  printf("\nThe Matrix multiplied by 2 is:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      matrix[i][j] *= 2;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  // Let's find the determinant of the Matrix
  int a = matrix[0][0], b = matrix[0][1], c = matrix[0][2];
  int d = matrix[1][0], e = matrix[1][1], f = matrix[1][2];
  int g = matrix[2][0], h = matrix[2][1], i = matrix[2][2];
  int determinant = (a * ((e * i) - (f * h))) - (b * ((d * i) - (f * g))) + (c * ((d * h) - (e * g)));
  printf("\nThe determinant of the Matrix is: %d\n", determinant);

  // Let's transpose the Matrix
  printf("\nThe transpose of the Matrix is:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%d ", matrix[j][i]);
    }
    printf("\n");
  }

  // Thank you for visiting the Matrix!
  printf("\nThank you for visiting the Matrix.\n");
  return 0;
}