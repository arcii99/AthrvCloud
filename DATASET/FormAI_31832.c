//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned long gcd(unsigned long a, unsigned long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

unsigned long lcm(unsigned long a, unsigned long b) {
  return (a*b)/gcd(a, b);
}

unsigned long mod_exp(unsigned long base, unsigned long exp, unsigned long modulus) {
  unsigned long result = 1;
  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp /= 2;
  }
  return result;
}

int is_prime(unsigned long number) {
  unsigned long i;
  if (number == 1) return 0;
  for (i = 2; i <= (unsigned long) sqrt(number); i++) {
    if (number % i == 0) {
      return 0;
    }
  }
  return 1;
}

unsigned long random_prime() {
  unsigned long number = rand() % 1000 + 1000;
  while (is_prime(number) != 1) number++;
  return number;
}

int main() {
    srand(time(NULL));
    int p = random_prime();
    int q = random_prime();
    unsigned long n = p*q;
    unsigned long phi_n = lcm(p-1, q-1);
    unsigned long e = rand() % phi_n + 2;
    while (gcd(e, phi_n) != 1) e++;
    unsigned long d = 0;
    while ((d*e) % phi_n != 1) d++;
    char message[1000];
    printf("Enter message (max length 1000 characters):\n");
    fgets(message, 1000, stdin);
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        unsigned long M = message[i];
        unsigned long C = mod_exp(M, e, n);
        printf("%u ", C);
    }
    printf("\n");
    return 0;
}