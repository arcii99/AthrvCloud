//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>

void fibonacci(int n) {
   int a = 0, b = 1, c, i;
   printf("%d, %d, ", a, b);

   for (i = 2; i < n; i++) {
      c = a + b;
      printf("%d, ", c);
      a = b;
      b = c;
   }
}

int main() {
   int n;

   printf("Enter the number of terms: ");
   scanf("%d", &n);

   if (n <= 0) {
      printf("Invalid input!");
   } else {
      printf("Fibonacci sequence: ");
      fibonacci(n);
   }

   return 0;
}