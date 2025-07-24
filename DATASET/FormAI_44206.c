//FormAI DATASET v1.0 Category: Recursive ; Style: visionary
#include <stdio.h>

int fibonacci(int n) {
   if(n == 0 || n == 1) {
      return n;
   }
   else {
      return (fibonacci(n-1) + fibonacci(n-2));
   }
}

int main() {
   int n, i;
   printf("Enter the number of terms you want to generate: ");
   scanf("%d", &n);
   printf("The Fibonacci sequence for the first %d terms: ", n);
   for(i = 0; i < n; i++) {
      printf("%d ", fibonacci(i));
   }
   printf("\n");
   return 0;
}