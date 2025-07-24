//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>

int fibonacci(int n) {
  if (n == 0 || n == 1) { 
    return n; 
  } else { 
    return fibonacci(n-1) + fibonacci(n-2); 
  }
}

int main() {
  int n;
  
  printf("Enter the number of terms in the Fibonacci sequence you'd like to generate: ");
  scanf("%d", &n);
  
  printf("The first %d terms in the Fibonacci sequence are: \n", n);
  
  for(int i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }
  
  return 0;
}