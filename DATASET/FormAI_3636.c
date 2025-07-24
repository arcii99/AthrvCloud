//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* This program generates random numbers within a given range and calculates their average, variance and standard deviation 
   using a performance-critical algorithm known as Welford's Online Algorithm.*/

#define N 1000000 /* Total number of random numbers to generate */
#define RANGE_MIN 1 /* Minimum value of the range */
#define RANGE_MAX 100 /* Maximum value of the range */

int main()
{
  int i;
  double x;
  double mean = 0, variance = 0, std_dev = 0;
  double delta, delta_squared;
  
  srand(time(NULL)); /* Initialization of the random number generator */
  
  for(i=1; i<=N; i++) /* Loop to generate the random numbers and calculate the statistics */
  {
    x = (double)rand()/(double)(RAND_MAX) * (RANGE_MAX-RANGE_MIN) + RANGE_MIN; /* Generating a random number with range [RANGE_MIN, RANGE_MAX] */
    
    delta = x - mean;
    mean = mean + delta/i;
    delta_squared = x - mean;
    variance = variance + delta*delta_squared;
    
    printf("Random number %d: %f\n", i, x); /* Print the generated random number */
  }
  
  variance = variance / (N - 1);
  std_dev = sqrt(variance);
  
  printf("Mean: %f\n", mean); /* Print the calculated mean */
  printf("Variance: %f\n", variance); /* Print the calculated variance */
  printf("Standard Deviation: %f\n", std_dev); /* Print the calculated standard deviation */
  
  return 0;
}