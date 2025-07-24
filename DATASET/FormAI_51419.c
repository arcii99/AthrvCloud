//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  int n = 7; // Size of matrix

  // Initializing the matrix
  char mat[n][n]; 
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      mat[i][j] = '#';
    }
  }

  // Printing the C pattern
  for(int i = 0; i < n; i++) {
    printf("\n");
    for(int j = 0; j < n; j++) {
      if(i == 0 || i == n-1 || j == 0) { // Top, bottom and left side of C
        printf("%c ", mat[i][j]);
      }
      else if(j == n-1 && i != 0 && i != n-1) { // Right side of C (excluding top and bottom)
        printf("%c ", mat[i][j]);
        for(int k = 0; k < i-1; k++) {
          printf("  "); // Creating space inside the C letter
        }
        printf("%c ", mat[i][j]);
      }
      else {
        printf("  "); // Creating space inside the C letter
      }
    }
  }

  return 0;
}