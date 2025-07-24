//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: systematic
#include <stdio.h>

// Function to check if a number is prime or not
int isPrime(int num) {
  // Return false if the number is less than 2
  if (num < 2) {
    return 0;
  }
  // Check for factors of the number from 2 to num-1
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  // Return true if no factors were found
  return 1;
}

int main() {
  int maxNum, primeCount = 0;
  printf("Enter the maximum number to find prime numbers: ");
  scanf("%d", &maxNum);

  // Print the prime numbers from 2 to maxNum
  for (int i = 2; i <= maxNum; i++) {
    if (isPrime(i)) {
      printf("%d ", i);
      primeCount++;
    }
  }
  printf("\nFound %d prime numbers between 2 and %d.\n", primeCount, maxNum);
  return 0;
}