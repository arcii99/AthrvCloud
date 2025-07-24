//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

int fibonacci(int n);

int main() {
   int n, result;

   printf("Enter the nth term: ");
   scanf("%d", &n);

   result = fibonacci(n);

   printf("The %dth term of Fibonacci series is %d.\n", n, result);

   return 0;
}

int fibonacci(int n) {
   if (n == 0 || n == 1) {
      return n;
   } else {
      return (fibonacci(n-1) + fibonacci(n-2));
   }
}