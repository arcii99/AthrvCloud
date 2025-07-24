//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: safe
#include <stdio.h>

int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int length, i, j;

  printf("Enter the length of the Fibonacci Sequence: ");
  scanf("%d", &length);

  int sequence[length];

  for (i = 0; i < length; i++) {
    sequence[i] = fibonacci(i);
  }

  // Print the sequence visually
  for (i = 0; i < length; i++) {
    for (j = 0; j < sequence[i]; j++) {
      printf("# ");
    }
    printf("\n");
  }

  return 0;
}