//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include <stdio.h>

int recursiveFunc(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return recursiveFunc(n - 1) + recursiveFunc(n - 2);
  }
}

int main() {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Error: Please enter a positive integer.\n");
    return -1;
  }

  printf("The Fibonacci sequence for %d terms is: ", n);

  for (int i = 0; i < n; i++) {
    printf("%d ", recursiveFunc(i));
  }

  printf("\n");

  return 0;
}