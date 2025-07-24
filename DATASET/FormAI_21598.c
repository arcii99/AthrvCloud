//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num, i, fib1 = 0, fib2 = 1, next;

  printf("Enter the number of terms in Fibonacci sequence: ");
  scanf("%d", &num);

  printf("\nFibonacci Sequence:\n");

  for (i = 1; i <= num; i++) {
    if (i == 1)
      printf("%d\n", fib1);
    else if (i == 2)
      printf("%d\n", fib2);
    else {
      next = fib1 + fib2;
      fib1 = fib2;
      fib2 = next;
      printf("%d\n", next);
    }

    //Visualization code starts here
    int j;

    for (j = 0; j < next; j++) {
      int k;

      for (k = 0; k < j; k++) {
        printf("*");
      }

      printf("\n");
    }

    printf("\n");
    //Visualization code ends here
  }

  return 0;
}