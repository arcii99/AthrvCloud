//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Romeo and Juliet
// Romeo and Juliet's Public Key Algorithm Implementation

// Scene 1: Initialize some variables
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int p, q, n, e, d, phi, plaintext, ciphertext;
  
  // Scene 2: Romeo generates two random primes, p and q
  srand(time(0));
  p = rand() % 100 + 1;
  q = rand() % 100 + 1;
  
  // Scene 3: Romeo calculates n and phi
  n = p * q;
  phi = (p - 1) * (q - 1);
  
  // Scene 4: Juliet chooses e
  for (e = 2; e < phi; e++) {
    if (gcd(e, phi) == 1) {
      break;
    }
  }
  
  // Scene 5: Romeo calculates d
  d = inverse(e, phi);
  
  // Scene 6: Romeo and Juliet share their public keys with each other
  printf("Romeo's public key: {%d, %d}\n", e, n);
  printf("Juliet's public key: {%d, %d}\n", e, n);
  
  // Scene 7: Romeo and Juliet use their private keys to encrypt and decrypt messages
  plaintext = 23;
  printf("Romeo's plaintext message: %d\n", plaintext);
  
  ciphertext = encrypt(plaintext, e, n);
  printf("Juliet receives ciphertext message: %d\n", ciphertext);
  
  plaintext = decrypt(ciphertext, d, n);
  printf("Juliet decrypts ciphertext message: %d\n", plaintext);
  
  return 0;
}

// Scene 8: The end!

// GCD function
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// Inverse function using extended euclidean algorithm
int inverse(int a, int b) {
  int q, r, s, t, s1 = 1, s2 = 0, t1 = 0, t2 = 1, temp = b;
  while(b != 0) {
    q = a / b;
    r = a % b;
    a = b;
    b = r;
    s = s1 - q * s2;
    s1 = s2;
    s2 = s;
    t = t1 - q * t2;
    t1 = t2;
    t2 = t;
  }
  if(s1 < 0)
    s1 += temp;
  return s1;
}

// Encryption function
int encrypt(int plaintext, int e, int n) {
  int ciphertext = 1;
  for (int i = 0; i < e; i++) {
    ciphertext = (ciphertext * plaintext) % n;
  }
  return ciphertext;
}

// Decryption function
int decrypt(int ciphertext, int d, int n) {
  int plaintext = 1;
  for (int i = 0; i < d; i++) {
    plaintext = (plaintext * ciphertext) % n;
  }
  return plaintext;
}