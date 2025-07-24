//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include<stdio.h>

//function to find the factorial of a number
int factorial(int n) {
  int i, f = 1;
  for(i = 2; i <= n; i++) {
    f *= i;
  }
  return f;
}

int main() {
  int n, i, j, k;
  printf("Enter the value of n: ");
  scanf("%d", &n);

  //creating a 3D array to store 10 matrices of size n*n
  int matrices[10][n][n];

  //generating 10 matrices of size n*n
  for(i = 0; i < 10; i++) {
    for(j = 0; j < n; j++) {
      for(k = 0; k < n; k++) {
        matrices[i][j][k] = (i+1) * factorial(j+k);
      }
    }
  }

  //finding the sum of all elements in all the matrices
  int sum = 0;
  for(i = 0; i < 10; i++) {
    for(j = 0; j < n; j++) {
      for(k = 0; k < n; k++) {
        sum += matrices[i][j][k];
      }
    }
  }

  printf("Sum of all elements in all the matrices: %d\n", sum);
  return 0;
}