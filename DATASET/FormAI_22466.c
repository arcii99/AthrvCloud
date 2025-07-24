//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <math.h>

/* Function to calculate log base n */
double log_base_n(double n, double x) {
  double result = log10(x) / log10(n);
  return result;
}

int main() {
  double x = 100;
  double base = 2;
  
  // Calculate log base 2 of 100
  double result = log_base_n(base, x);
  
  // Print the result
  printf("The result of log base %.2f of %.2f is %.2f", base, x, result);
  
  return 0;
}