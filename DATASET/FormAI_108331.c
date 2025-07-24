//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Function prototypes */
int gcd(int a, int b);
int calc_public_key(int p, int q, int e);
int calc_private_key(int p, int q, int e);
int encrypt_message(int message, int public_key);
int decrypt_message(int cipher, int private_key);

int main() {
  int p, q, e, message, cipher;
  printf("Welcome to our awesome Public-Key Algorithm Implementation program!\n\n");

  /* Generate two random prime numbers */
  srand(time(NULL));
  p = rand() % 100;
  q = rand() % 100;
  while (gcd(p, q) != 1) {
    p = rand() % 100;
    q = rand() % 100;
  }
  printf("The first random prime number is: %d\n", p);
  printf("The second random prime number is: %d\n\n", q);

  /* Calculate the public and private keys */
  e = rand() % (p*q);
  while (gcd(e, (p-1)*(q-1)) != 1) {
    e = rand() % (p*q);
  }
  printf("The public key is: %d\n", calc_public_key(p, q, e));
  printf("The private key is: %d\n\n", calc_private_key(p, q, e));

  /* Get the message from the user */
  printf("Enter a message to encrypt: ");
  scanf("%d", &message);

  /* Encrypt and decrypt the message */
  cipher = encrypt_message(message, calc_public_key(p, q, e));
  printf("The encrypted message is: %d\n", cipher);
  printf("The decrypted message is: %d\n", decrypt_message(cipher, calc_private_key(p, q, e)));

  return 0;
}

/* Function to calculate the greatest common divisor */
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

/* Function to calculate the public key */
int calc_public_key(int p, int q, int e) {
  return p * q * e;
}

/* Function to calculate the private key */
int calc_private_key(int p, int q, int e) {
  int d = e % ((p-1)*(q-1));
  while ((e*d) % ((p-1)*(q-1)) != 1) {
    d = rand() % ((p-1)*(q-1));
  }
  return d;
}

/* Function to encrypt a message */
int encrypt_message(int message, int public_key) {
  return fmod(pow(message, public_key), public_key);
}

/* Function to decrypt a message */
int decrypt_message(int cipher, int private_key) {
  return fmod(pow(cipher, private_key), private_key);
}