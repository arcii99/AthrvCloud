//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int fibonacci(int n) {
  if(n == 0) {
    return 0;
  } else if(n == 1) {
    return 1;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int n, result;
  
  printf("Enter the number of terms you want to generate: ");
  scanf("%d", &n);
  
  printf("The first %d terms of the Fibonacci sequence are:\n", n);
  
  for(int i=0; i<n; i++) {
    result = fibonacci(i);
    printf("%d ", result);
  }
  
  return 0;
}