//FormAI DATASET v1.0 Category: Educational ; Style: scalable
#include <stdio.h>

int main() {
  int num, i, j, count = 0;
  printf("Enter the number of prime numbers you want to generate: ");
  scanf("%d", &num);
  
  // allocate memory dynamically
  int *primes = malloc(sizeof(int) * num);
  if (primes == NULL) { // check if allocation was successful
    printf("Unable to allocate memory");
    return 1;
  }

  // loop through all numbers up to 1000 and find primes
  for (i = 2; count < num; i++) {
    for (j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        break;
      }
    }
    if (j > i / 2) {
      primes[count++] = i;
    }
  }

  // print out the primes
  printf("The first %d prime numbers are:\n", num);
  for (i = 0; i < num; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");

  // free up dynamically allocated memory
  free(primes);

  return 0;
}