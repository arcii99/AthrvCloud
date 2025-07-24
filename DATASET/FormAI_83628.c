//FormAI DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>

// vision-inspired matrix calculation example
// this program will calculate the inverse of a 3x3 matrix

int main() {
  float mat[3][3], inv[3][3], det;

  // matrix input
  printf("Enter the elements of the 3x3 matrix:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      scanf("%f", &mat[i][j]);
    }
  }

  // calculation of determinant
  det = (mat[0][0]*mat[1][1]*mat[2][2]) + (mat[0][1]*mat[1][2]*mat[2][0])
        + (mat[0][2]*mat[1][0]*mat[2][1]) - (mat[0][2]*mat[1][1]*mat[2][0])
        - (mat[0][0]*mat[1][2]*mat[2][1]) - (mat[0][1]*mat[1][0]*mat[2][2]);

  // matrix inverse calculation
  inv[0][0] = ((mat[1][1]*mat[2][2]) - (mat[1][2]*mat[2][1]))/det;
  inv[0][1] = ((mat[0][2]*mat[2][1]) - (mat[0][1]*mat[2][2]))/det;
  inv[0][2] = ((mat[0][1]*mat[1][2]) - (mat[0][2]*mat[1][1]))/det;

  inv[1][0] = ((mat[1][2]*mat[2][0]) - (mat[1][0]*mat[2][2]))/det;
  inv[1][1] = ((mat[0][0]*mat[2][2]) - (mat[0][2]*mat[2][0]))/det;
  inv[1][2] = ((mat[0][2]*mat[1][0]) - (mat[0][0]*mat[1][2]))/det;

  inv[2][0] = ((mat[1][0]*mat[2][1]) - (mat[1][1]*mat[2][0]))/det;
  inv[2][1] = ((mat[0][1]*mat[2][0]) - (mat[0][0]*mat[2][1]))/det;
  inv[2][2] = ((mat[0][0]*mat[1][1]) - (mat[0][1]*mat[1][0]))/det;

  // matrix inverse output
  printf("Inverse of the entered 3x3 matrix is:\n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%.2f\t", inv[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}