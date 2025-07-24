//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Function to find the greatest common divisor
int gcd(int num1, int num2) {
  int i;
  for (i = num1; i >= 1; i--) {
    if (num1 % i == 0 && num2 % i == 0) {
      break;
    }
  }
  return i;
}

// Function to generate a random prime number
int generate_prime(int lower, int upper) {
  int num, isPrime;
  do {
    num = (rand() % (upper - lower + 1)) + lower; // generate random number
    isPrime = is_prime(num); // check if the number is prime
  } while (!isPrime);
  return num;
}

int main() {
  int plain_text, cipher_text, decrypted_text;

  int p = generate_prime(100, 1000); // generate a random prime number p
  int q = generate_prime(100, 1000); // generate a random prime number q

  int n = p * q; // calculate the value of n
  int totient = (p - 1) * (q - 1); // calculate the value of totient

  int e = 3; // choose a public key exponent e

  while (gcd(e, totient) != 1) { // ensure that e and totient are coprime
    e += 2;
  }

  int d = 0; // initialize the private key exponent d

  for (int i = 1; i < totient; i++) {
    if ((i * e) % totient == 1) { // calculate the modular multiplicative inverse of e
      d = i;
      break;
    }
  }

  printf("Public key: (%d, %d)\n", e, n);
  printf("Private key: (%d, %d)\n", d, n);

  printf("Enter a plaintext: ");
  scanf("%d", &plain_text);

  cipher_text = pow(plain_text, e); // encrypt the plaintext
  cipher_text = cipher_text % n;

  printf("Encrypted text: %d\n", cipher_text);

  decrypted_text = pow(cipher_text, d); // decrypt the ciphertext
  decrypted_text = decrypted_text % n;

  printf("Decrypted text: %d\n", decrypted_text);

  return 0;
}