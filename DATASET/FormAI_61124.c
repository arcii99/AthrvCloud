//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Claude Shannon
#include <stdio.h>

// Function to check if a number is prime or not
int is_prime(int num) {
  if (num <= 1) {
    return 0; // Not a prime number
  }
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      return 0; // Not a prime number
    }
  }
  return 1; // Number is prime
}

int main() {
  int n;
  printf("Enter the value of n: ");
  scanf("%d", &n); // Input the number of prime numbers to be generated
  
  int primes[n];
  int count = 0;
  int num = 2;
  
  while (count < n) {
    if (is_prime(num)) {
      primes[count++] = num; // Add to the primes array if prime
    }
    num++;
  }
  
  // Print the generated prime numbers
  printf("The first %d prime numbers are:\n", n);
  for (int i = 0; i < n; i++) {
    printf("%d\n", primes[i]);
  }
  
  return 0; // Program ends here
}