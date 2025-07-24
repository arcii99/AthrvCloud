//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

/* recursive function to calculate factorial of a number */
int factorial(int n) {
   if (n == 1 || n == 0) { // base case: factorial of 1 or 0 is 1
      return 1;
   }
   else { // recursive case: multiply n by factorial of (n-1)
      return n * factorial(n - 1);
   }
}

int main() {
   int num;
   printf("Enter a number to calculate its factorial: ");
   scanf("%d", &num);

   if (num < 0) { // error checking: negative numbers don't have a factorial
      printf("Error: Factorial not defined for negative numbers.\n");
   }
   else {
      printf("Factorial of %d is %d\n", num, factorial(num));
   }

   return 0;
}