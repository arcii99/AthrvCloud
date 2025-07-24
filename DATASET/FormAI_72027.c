//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include <stdio.h>

int fibonacci(int n) {
  if(n <= 1) {
    return n;
  }
  else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int n = 0;
  printf("Enter a number to generate the fibonacci sequence:\n");
  scanf("%d", &n);

  printf("The fibonacci sequence for %d terms is:\n", n);
  for(int i = 0; i < n; i++) {
    printf("%d ", fibonacci(i));
  }
  return 0;
}