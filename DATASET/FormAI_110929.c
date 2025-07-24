//FormAI DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define a function to calculate factorial */
long long factorial(int n) {
  long long result = 1;
  for(int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  
  int n, k;
  double combination;
  
  /* Get user input */
  printf("Enter the value of n: ");
  scanf("%d", &n);
  
  printf("Enter the value of k: ");
  scanf("%d", &k);
  
  /* Calculate combination using math formula */
  combination = factorial(n) / (factorial(k) * factorial(n - k));
  
  /* Print the result */
  printf("The combination of %d choose %d is: %g\n", n, k, combination);
  
  return 0;
}