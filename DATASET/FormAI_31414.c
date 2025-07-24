//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: mind-bending
#include <stdio.h>

// Function to find the GCD of two numbers
int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  return gcd(b%a, a);
}

// Function to find the modular multiplicative inverse of a number
int mod_inv(int a, int m) {
  int m0 = m, t, q;
  int x0 = 0, x1 = 1;

  if (m == 1) {
    return 0;
  }

  while (a > 1) {
    // q is quotient
    q = a / m;

    t = m;

    // m is remainder now, process same as Euclid's algo
    m = a % m, a = t;

    t = x0;

    x0 = x1 - q * x0;

    x1 = t;
  }

  // Make sure x1 is positive
  if (x1 < 0) {
    x1 += m0;
  }

  return x1;
}

// Function to generate keys and encrypt/decrypt data
void generate_keys(int p, int q) {
  // Calculate n and phi(n)
  int n = p * q;
  int phi_n = (p - 1) * (q - 1);

  // Choose a public key e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
  int e = 2;
  while (e < phi_n) {
    if (gcd(e, phi_n) == 1) {
      break;
    }
    e++;
  }

  // Calculate the private key d such that d = e^-1 mod phi(n)
  int d = mod_inv(e, phi_n);

  printf("Public key (n, e): (%d, %d)\n", n, e);

  printf("Private key (n, d): (%d, %d)\n", n, d);

  // Test encryption and decryption using some data
  int data = 123;
  printf("Original data: %d\n", data);

  // Encrypt data using the public key (n, e)
  int encrypted_data = 1;
  for (int i = 1; i <= e; i++) {
    encrypted_data = (encrypted_data * data) % n;
  }
  printf("Encrypted data: %d\n", encrypted_data);

  // Decrypt data using the private key (n, d)
  int decrypted_data = 1;
  for (int i = 1; i <= d; i++) {
    decrypted_data = (decrypted_data * encrypted_data) % n;
  }
  printf("Decrypted data: %d\n", decrypted_data);
}

// Main function
int main() {
  int p = 17;
  int q = 19;

  generate_keys(p, q);

  return 0;
}