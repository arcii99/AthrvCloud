//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of prime numbers
#define MAX_PRIME_NUMS 100

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// Function to generate the prime numbers
void generate_primes(int start, int end, int primes[]) {
  int num = 0;
  bool is_prime;

  // Check each number within the range
  for (int i = start; i<= end; i++) {
    is_prime = true;

    // Check if the number is prime
    for (int j = 2; j < i; j++) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }

    // If the number is prime, add it to the primes array
    if (is_prime) {
      primes[num++] = i;

      // Check if the maximum number of primes has been reached
      if (num == MAX_PRIME_NUMS) {
        break;
      }
    }
  }
}

// Function to generate the public and private keys
void generate_keys(int p, int q, int *n_ptr, int *e_ptr, int *d_ptr) {
  int n, phi, e, d;

  // Calculate the value of n
  n = p * q;
  *n_ptr = n;

  // Calculate the value of phi
  phi = (p - 1) * (q - 1);

  // Choose a value of e such that it is coprime with phi
  for (int i = 2; i < phi; i++) {
    if (gcd(i, phi) == 1) {
      e = i;
      break;
    }
  }
  *e_ptr = e;

  // Calculate the value of d such that e * d is congruent to 1 (mod phi)
  for (int i = 1; i < phi; i++) {
    if ((e * i) % phi == 1) {
      d = i;
      break;
    }
  }
  *d_ptr = d;
}

int main() {
  int primes[MAX_PRIME_NUMS];
  int n, e, d;

  // Generate the prime numbers
  generate_primes(2, 100, primes);

  // Choose two prime numbers randomly
  int p = primes[rand() % MAX_PRIME_NUMS];
  int q = primes[rand() % MAX_PRIME_NUMS];

  // Generate the keys
  generate_keys(p, q, &n, &e, &d);

  // Output the public and private keys
  printf("Public key: (%d, %d)\n", n, e);
  printf("Private key: (%d, %d)\n", n, d);

  return 0;
}