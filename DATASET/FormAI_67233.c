//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: visionary
/* A Performance-Critical Component Example Program */
/* This program calculates the first 100000 prime numbers */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

int main()
{
  int nums[SIZE], i, j;
  int primes[SIZE], num_of_primes = 0;

  /* Set all numbers to be prime initially */
  for(i=0; i<SIZE; ++i) nums[i] = 1;

  /* Mark all composite numbers */
  for(i=2; i<=SIZE; ++i) {
    if(nums[i-1]) {
      for(j=i+i; j<=SIZE; j+=i) {
        nums[j-1] = 0;
      }
    }
  }

  /* Store the prime numbers in an array */
  for(i=2; i<=SIZE; ++i) {
    if(nums[i-1]) {
      primes[num_of_primes++] = i;
    }
  }

  /* Print the prime numbers */
  printf("The first %d prime numbers are:\n", SIZE);
  for(i=0; i<num_of_primes; ++i) {
    printf("%d\n", primes[i]);
  }

  return 0;
}