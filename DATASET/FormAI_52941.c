//FormAI DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>

int fibonacci(int n) {
  if (n == 0) { // Base case for recursion
    return 0;
  } else if (n == 1) { // Base case for recursion
    return 1;
  } else { // Recursive case
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int n;
  printf("Thou wisheth to know the n-th term of the Fibonacci sequence? Enter a non-negative integer value for n: ");
  scanf("%d", &n);
  printf("The %d-th term of the Fibonacci sequence is %d.\n", n, fibonacci(n));
  return 0;
}