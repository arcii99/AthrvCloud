//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;

  for (int i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }

  return true;
}

int main() {
  const int MAX_PRIME_NUMBERS = 50;
  int primeNumberCount = 0;
  int numberToCheckIfPrime = 2;
  int primeNumbers[MAX_PRIME_NUMBERS];
  int numberOfDivisors[MAX_PRIME_NUMBERS];
  
  while (primeNumberCount < MAX_PRIME_NUMBERS) {
    int numberOfDivisorsCurrentNumber = 0;
    for (int i = 1; i <= numberToCheckIfPrime; i++) {
      if (numberToCheckIfPrime % i == 0) numberOfDivisorsCurrentNumber++;
    }
    if (isPrime(numberToCheckIfPrime) && numberOfDivisorsCurrentNumber == 2) {
      primeNumbers[primeNumberCount] = numberToCheckIfPrime;
      numberOfDivisors[primeNumberCount] = numberOfDivisorsCurrentNumber;
      primeNumberCount++;
    }
    else {
      for (int i = 0; i < primeNumberCount; i++) {
        if (numberToCheckIfPrime % primeNumbers[i] == 0) {
          numberOfDivisorsCurrentNumber = numberOfDivisors[i] + 1;
          break;
        }
      }
      if (numberOfDivisorsCurrentNumber == 2) {
        primeNumbers[primeNumberCount] = numberToCheckIfPrime;
        numberOfDivisors[primeNumberCount] = numberOfDivisorsCurrentNumber;
        primeNumberCount++;
      }
    }
    numberToCheckIfPrime++;
  }

  printf("The first %d prime numbers (in ascending order) are:\n", MAX_PRIME_NUMBERS);
  for (int i = 0; i < MAX_PRIME_NUMBERS; i++) {
    printf("%d\n", primeNumbers[i]);
  }

  return 0;
}