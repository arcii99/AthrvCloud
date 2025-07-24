//FormAI DATASET v1.0 Category: Educational ; Style: mathematical
/*
  This is a program that demonstrates a mathematical formula for computing the sum of a given series:
  S = 1 + 2/2^2 + 3/3^2 + ... + n/n^2
  
  The program prompts the user to enter the value of n and computes and prints the sum of the series.
*/

#include <stdio.h>
#include <math.h>

int main() {
  
  int n, i;
  double series_sum = 0.0;
  
  printf("Enter the value of n: ");
  scanf("%d", &n);
  
  for (i = 1; i <= n; i++) {
    
    series_sum += (double)i / pow(i, 2);
    
  }
  
  printf("The sum of the series is: %lf\n", series_sum);
  
  return 0;
}