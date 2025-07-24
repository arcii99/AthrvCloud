//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

void printPrimes(int lowerBound, int upperBound) {
  printf("The prime numbers between %d and %d are:\n", lowerBound, upperBound);
  for (int i = lowerBound; i <= upperBound; i++) {
    if (isPrime(i)) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

int main() {
  int lowerBound, upperBound;
  printf("Enter the lower bound: ");
  scanf("%d", &lowerBound);
  printf("Enter the upper bound: ");
  scanf("%d", &upperBound);
  printPrimes(lowerBound, upperBound);
  return 0;
}

/*
Sample Output:
Enter the lower bound: 1
Enter the upper bound: 20
The prime numbers between 1 and 20 are:
2 3 5 7 11 13 17 19
*/