//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: invasive
#include <stdio.h>

int main() {
  int a = 0, b = 1, c, n;
  printf("Enter the number of terms: ");
  scanf("%d", &n);
  printf("%d %d ", a, b);  // Print the first two numbers in the sequence
  for (int i=2; i<n; i++) {  // Generate the remaining terms in the sequence
    c = a + b;
    printf("%d ", c);
    a = b;
    b = c;
  }

  printf("\n\nFibonacci sequence visualized:\n\n");

  // Visualize the sequence of numbers using asterisks
  for (int i=0; i<n; i++) {
    a = 0;
    b = 1;
    for (int j=1; j<=i; j++) {
      c = a + b;
      a = b;
      b = c;
    }
    for (int k=0; k<c; k++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}