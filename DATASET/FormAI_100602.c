//FormAI DATASET v1.0 Category: Scientific ; Style: inquisitive
#include <stdio.h>

/* This program calculates the sum of the first n terms of the Fibonacci sequence.
 * The user is prompted to enter the value of n.
 * The sum is printed to the console.
 */

int main() {
  int n;
  double sum = 0;
  
  printf("How many terms do you want to sum? ");
  scanf("%d", &n);
  
  int i; // Declare i outside of for loop so that it can be used later.
  for (i = 1; i <= n; i++) {
    double fib_i; // Declare fib_i inside of loop so that it is re-initialized for each iteration.
    
    if (i == 1) {
      fib_i = 1;
    } else if (i == 2) {
      fib_i = 1;
    } else {
      double fib_i_minus_1 = 1;
      double fib_i_minus_2 = 1;
      
      int j;
      for (j = 3; j <= i; j++) {
        fib_i = fib_i_minus_1 + fib_i_minus_2;
        fib_i_minus_2 = fib_i_minus_1;
        fib_i_minus_1 = fib_i;
      }
    }
    
    sum += fib_i;
  }
  
  printf("The sum of the first %d terms of the Fibonacci sequence is %.0lf.", n, sum);
  
  return 0;
}