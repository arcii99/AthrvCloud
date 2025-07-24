//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: configurable
#include <stdio.h>

int main() {
   int n, i, first = 0, second = 1, next;

   printf("Enter the number of terms: ");
   scanf("%d", &n);

   printf("\nFibonacci Series:\n");

   for (i = 0; i < n; i++) {
      if (i <= 1)
         next = i;
      else {
         next = first + second;
         first = second;
         second = next;
      }
      printf("%d ", next);
   }

   return 0;
}