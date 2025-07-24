//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>

int main()
{
  // Program Header
  printf("=~=~=~=~ Welcome to the Mind-Bending Prime Number Generator =~=~=~=~=\n");
  printf("\nThis program will generate a list of prime numbers between ");
  printf("two user-specified numbers. Let's get started!\n\n");

  // Getting User Input
  int start, end, foundPrime, isPrime;
  printf("Please enter the start number: ");
  scanf("%d", &start);
  printf("Please enter the end number: ");
  scanf("%d", &end);

  // Evaluate Input for Primeness
  printf("\nCalculating prime numbers between %d and %d...\n\n", start, end);
  for (int i = start; i <= end; i++) {
    foundPrime = 1;
    isPrime = 1;
    if (i <= 1) {
      isPrime = 0;
      continue;
    }
    for (int j = 2; j <= i / 2; ++j) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime) {
      printf("%d is a prime number.\n", i);
      foundPrime = 1;
    }
  }

  // Program Footer
  printf("\n=~=~=~=~ Prime Number Generation Complete =~=~=~=~=\n");
  printf("\nThank you for using this mind-bending program!\n");

  return 0;
}