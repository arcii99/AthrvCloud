//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
  int temp;
  while(b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int p, q, n, e, d;
  int phi, message, cypher;

  printf("Enter two prime numbers (p and q): ");
  scanf("%d %d", &p, &q);

  n = p * q;
  phi = (p - 1) * (q - 1);

  // Public key generation
  printf("Enter a prime number for 'e' such that 1 < e < %d: ", phi);
  do {
    scanf("%d", &e);
  } while(gcd(e, phi) != 1);

  // Private key generation
  d = fmod(1/e, phi);

  printf("Enter the message: ");
  scanf("%d", &message);

  // Encryption
  cypher = fmod(pow(message, e), n);
  printf("Encrypted message: %d\n", cypher);

  // Decryption
  message = fmod(pow(cypher, d), n);
  printf("Decrypted message: %d\n", message);

  return 0;
}