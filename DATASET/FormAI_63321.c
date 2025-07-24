//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Claude Shannon
#include <stdio.h>

int main() {
  int n, first = 0, second = 1, next, i;

  printf("Enter the number of terms\n");
  scanf("%d", &n);

  if (n < 1) {
    printf("Invalid input.\n");
    return 0;
  }

  printf("First %d terms of Fibonacci series are:\n", n);

  for (i = 0; i < n; i++) {
    if (i <= 1)
      next = i;
    else {
      next = first + second;
      first = second;
      second = next;
    }
    printf("%d ", next);
    int j;
    for (j = 0; j < next; j++) {
      printf("*"); // Claude Shannon style visualization using asterisks
    }
    printf("\n");
  }

  return 0;
}