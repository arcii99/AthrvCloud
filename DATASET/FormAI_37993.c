//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Public-Key Algorithm Implementation

// Generate random prime number (not optimized)
int generate_prime() {
  int num, i, is_prime = 1;
  // Loop until a prime is found
  while (is_prime) {
    num = rand() % 100;
    is_prime = 0;
    // Check if num is prime
    for (i = 2; i <= num / 2; ++i) {
      if (num % i == 0) {
        is_prime = 1;
        break;
      }
    }
  }
  return num;
}

// Extended Euclidean Algorithm to find the private key
int extended_euclidean(int a, int b) {
  int r0 = a, r1 = b, s0 = 1, s1 = 0, t0 = 0, t1 = 1, q, r2, s2, t2;
  while (r1 != 0) {
    q = r0 / r1;
    r2 = r0 % r1;
    s2 = s0 - q * s1;
    t2 = t0 - q * t1;
    r0 = r1;
    s0 = s1;
    t0 = t1;
    r1 = r2;
    s1 = s2;
    t1 = t2;
  }
  return t0;
}

int main() {
  int p, q, n, phi, e, d, msg, encrypted_msg, decrypted_msg;
  
  // Generate random prime numbers
  p = generate_prime();
  q = generate_prime();
  
  // Calculate n and phi
  n = p * q;
  phi = (p - 1) * (q - 1);
  
  // Choose a random integer e such that 1 < e < phi and gcd(e, phi) = 1
  e = rand() % (phi - 1) + 1;
  while (extended_euclidean(e, phi) != 1) {
    e = rand() % (phi - 1) + 1;
  }
  
  // Calculate d such that d * e ≡ 1 (mod phi)
  d = extended_euclidean(e, phi);
  
  // Get message to encrypt
  printf("Enter a message to encrypt: ");
  scanf("%d", &msg);
  
  // Encrypt message
  encrypted_msg = (int)pow(msg, e) % n;
  printf("Encrypted message: %d\n", encrypted_msg);
  
  // Decrypt message
  decrypted_msg = (int)pow(encrypted_msg, d) % n;
  printf("Decrypted message: %d\n", decrypted_msg);
  
  return 0;
}