//FormAI DATASET v1.0 Category: Educational ; Style: Donald Knuth
#include <stdio.h>

int main() {
  int n = 7;
  int arr[n][n];

  // filling the matrix
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == 0) {
        arr[i][j] = j + 1;
      } else if(j == 0) {
        arr[i][j] = i + 1;
      } else {
        arr[i][j] = arr[i-1][j] + arr[i][j-1];
      }
    }
  }

  // printing the matrix
  printf("The Pascal's Triangle of order %d is:\n", n);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d\t", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}