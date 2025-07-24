//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>

int recursiveSum(int n);

int main() {
   int n, sum;
   
   printf("Enter a positive integer: ");
   scanf("%d", &n);

   sum = recursiveSum(n);

   printf("Sum of first %d natural numbers = %d\n", n, sum);
   return 0;
}

int recursiveSum(int n) {
   if (n != 0)
       return n + recursiveSum(n-1);
   else
       return n;
}