//FormAI DATASET v1.0 Category: Educational ; Style: scientific
//This program computes the value of the Fibonacci sequence up to the given number n using a recursive function and returns the value at the specified index i.
#include <stdio.h>

//recursive function to compute Fibonacci sequence
int fibonacci(int n) {
   if(n <= 1) {
      return n;
   }
   return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
   int n, i;

   printf("Enter the value of n: ");
   scanf("%d", &n);

   //print the Fibonacci sequence up to n
   printf("Fibonacci sequence up to %d: ", n);
   for(i = 0; i < n; i++) {
      printf("%d ", fibonacci(i));
   }

   //get the value at index i
   printf("\nEnter the value of i: ");
   scanf("%d", &i);
   printf("Value at index %d: %d", i, fibonacci(i));

   return 0;
}