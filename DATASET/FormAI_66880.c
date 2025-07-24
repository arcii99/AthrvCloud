//FormAI DATASET v1.0 Category: Recursive ; Style: careful
#include <stdio.h>

int factorial(int n) {
   if(n < 0) {
      return -1; // error condition: negative input
   } else if(n == 0) {
      return 1; // base case
   } else {
      return n * factorial(n-1); // recursive case
   }
}

int main() {
   int n;
   printf("Enter a non-negative integer: ");
   scanf("%d", &n);
   int result = factorial(n);
   if(result == -1) {
      printf("Error: negative input.\n");
   } else {
      printf("%d! = %d\n", n, result);
   }
   return 0;
}