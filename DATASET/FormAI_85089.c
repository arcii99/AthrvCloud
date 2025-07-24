//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n;
  float randomNum;
  
  printf("Enter the number of random numbers between 0 and 1 to generate: ");
  scanf("%d", &n);
  
  // Set seed for random number generator
  srand(time(0));
  
  // Generate n random numbers between 0 and 1
  printf("The random numbers are:\n");
  for (i = 0; i < n; i++) {
    randomNum = (float)rand() / RAND_MAX;
    printf("%f\n", randomNum);
  }
  
  return 0;
}