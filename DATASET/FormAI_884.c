//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>

int main() {
  int n, f1 = 0, f2 = 1, next;

  printf("Enter the number of terms in the Fibonacci sequence: ");
  scanf("%d", &n);

  printf("Fibonacci Sequence: ");

  for (int i = 0; i < n; i++) {
    if (i <= 1)
      next = i;
    else {
      next = f1 + f2;
      f1 = f2;
      f2 = next;
    }
    printf("%d ", next);
  }
  return 0;
}