//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// function to calculate power
long long power(long long x, unsigned int y, long long p) {
  long long res = 1;
  x = x % p;

  while (y > 0) {
    if (y & 1)
      res = (res*x) % p;

    y = y>>1;
    x = (x*x) % p;
  }
  return res;
}

// function to check if a number is prime
int is_prime(long long n) {
  if (n <= 1 || n == 4) {
    return 0;
  }
  if (n <= 3) {
    return 1;
  }

  long long d = n-1;
  while (d % 2 == 0) {
    d /= 2;
  }

  int k = 5;
  while (k--) {
    long long a = rand() % (n-4) + 2;
    long long x = power(a, d, n);
    if (x == 1 || x == n-1)
      continue;

    int i;
    for (i = 0; i < d-1; i++) {
      x = (x*x) % n;
      if (x == 1)
        return 0;
      if (x == n-1)
        break;
    }
    if (i == d-1)
      return 0;
  }
  return 1;
}

// function to generate prime numbers
long long generate_prime() {
  long long n;
  do {
    n = rand();
  } while (!is_prime(n));
  return n;
}

// function to calculate gcd
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// function to calculate multiplicative inverse
long long mod_inverse(long long a, long long m) {
  a = a % m;
  for (long long x = 1; x < m; x++) {
    if ((a*x) % m == 1) {
      return x;
    }
  }
}

// main function
int main() {
  // generating two prime numbers
  long long p = generate_prime();
  long long q = generate_prime();
  
  // calculating n and phi(n)
  long long n = p*q;
  long long phi_n = (p-1)*(q-1);

  // generating a random number between 1 and phi(n)
  long long e;
  do {
    e = rand() % phi_n + 1;
  } while (gcd(e, phi_n) != 1);

  // calculating d, the multiplicative inverse of e modulo phi(n)
  long long d = mod_inverse(e, phi_n);

  // printing the public and private keys
  printf("Public key: (%lld, %lld)\n", e, n);
  printf("Private key: (%lld, %lld)\n", d, n);

  return 0;
}