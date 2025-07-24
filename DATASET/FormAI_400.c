//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include <stdio.h>

int fibonacci(int n) {
  if(n<=1) {
      return n;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
  int i, n;
  printf("Enter the number of terms in the Fibonacci series: ");
  scanf("%d", &n);

  printf("Fibonacci series:");
  for(i=0; i<n; i++){
      printf(" %d", fibonacci(i));
  }
  return 0;
}