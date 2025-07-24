//FormAI DATASET v1.0 Category: Recursive ; Style: dynamic
#include <stdio.h>

// A dynamic style recursive function to calculate factorial.
int factorial(int n) {
   if (n == 0) // base case
      return 1;
   else
      return n * factorial(n-1); // recursive case
}

int main() {
   int num;
   printf("Enter a positive integer: ");
   scanf("%d", &num);
   
   if (num < 0) {
      printf("Error! Factorial of a negative number doesn't exist.");
   } else {
      printf("Factorial of %d is %d", num, factorial(num));
   }
   
   return 0;
}