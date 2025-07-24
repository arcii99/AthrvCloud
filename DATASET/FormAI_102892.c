//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>

void fibVisual(int n);

int main() {
  int n;
  printf("Enter the nth term of the Fibonacci Sequence to visualize: ");
  scanf("%d", &n);
  fibVisual(n);

  return 0;
}

void fibVisual(int n) {
  int i, j, a = 0, b = 1, sum;
  printf("Fibonacci Sequence:\n");
  printf("%d\n", a);
  printf("%d\n", b);
  for (i = 2; i <= n; i++) {
    sum = a + b;
    a = b;
    b = sum;
    for (j = 1; j <= sum; j++) {
      if (j == sum) {
        printf("*\n");
      } else {
        printf("* ");
      }
    }
  }
}