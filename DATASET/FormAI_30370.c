//FormAI DATASET v1.0 Category: Educational ; Style: Ada Lovelace
/* 
  Program to calculate first n prime numbers
  Inspired by Ada Lovelace's work on algorithmic thinking

  Written by [Your Name]
  Date: [Current Date]
*/

#include <stdio.h>

// Function to check if number is prime
int is_prime(int num) {
  if (num <= 1) {
    return 0;
  }
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n;
  printf("Enter the number of prime numbers you want to calculate: ");
  scanf("%d", &n);
  
  int primes[n];
  int count = 0;
  int num = 2;
  
  while (count < n) {
    if (is_prime(num)) {
      primes[count] = num;
      count++;
    }
    num++;
  }
  
  printf("The first %d prime numbers are:\n", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", primes[i]);
  }
  printf("\n");
  
  return 0;
}