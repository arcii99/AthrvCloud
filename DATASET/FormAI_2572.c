//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: imaginative
#include <stdio.h>

int fibonacci(int n) {
   if (n <= 1) {
      return n;
   } else {
      return fibonacci(n-1) + fibonacci(n-2);
   }
}

int main() {
   int n, i = 0, c;
 
   printf("Enter the number of terms: ");
   scanf("%d", &n);
 
   printf("Fibonacci Sequence:\n");
   for (c = 1; c <= n; c++) {
      printf("%d ", fibonacci(i));
      i++;
   }
 
   return 0;
}