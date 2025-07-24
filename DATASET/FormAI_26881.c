//FormAI DATASET v1.0 Category: Scientific ; Style: recursive
#include <stdio.h>

int fibonacci(int term) {
  if (term == 0 || term == 1) {
    return term;
  }
  else {
    return fibonacci(term-1) + fibonacci(term-2);
  }
}

int main() {
  int n;
  printf("Enter the number of terms to generate in the Fibonacci sequence:");
  scanf("%d", &n);
  printf("Fibonacci sequence:\n");
  for (int i=0; i<n; i++) {
    printf("%d ", fibonacci(i));
  }
  return 0;
}