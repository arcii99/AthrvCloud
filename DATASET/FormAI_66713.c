//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

int fibonacci(int n) {
   if (n == 0) {
      return 0;
   } else if (n == 1) {
      return 1;
   } else {
      return (fibonacci(n-1) + fibonacci(n-2));
   }
}

int main() {
   int i, j;

   printf("This program will print the Fibonacci sequence from 0 to 20\n\n");

   for (i = 0; i <= 20; i++) {
      j = fibonacci(i);
      printf("%d ", j);
   }

   return 0;
}