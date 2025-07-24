//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// generate random prime numbers
int generate_prime(int start, int end) {
  srand(time(NULL));
  int num = (rand() % (end - start + 1)) + start;
  if (num % 2 == 0) num++;
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      num += 2;
      i = 3;
    }
  }
  return num;
}

// calculate the greatest common divisor
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

// generate the public and private keys
void generate_keys(int p, int q, int *n, int *e, int *d) {
  // calculate n
  *n = p * q;

  // calculate phi(n)
  int phi = (p - 1) * (q - 1);

  // choose e
  srand(time(NULL));
  *e = (rand() % (phi - 2 + 1)) + 2;
  while (gcd(*e, phi) != 1) {
    *e = (rand() % (phi - 2 + 1)) + 2;
  }

  // calculate d
  int k = 1;
  while ((k * phi + 1) % *e != 0) {
    k++;
  }
  *d = (k * phi + 1) / *e;
}

// encrypt the message
int encrypt(int m, int e, int n) {
  int c = 1;
  for (int i = 0; i < e; i++) {
    c = (c * m) % n;
  }
  return c;
}

// decrypt the message
int decrypt(int c, int d, int n) {
  int m = 1;
  for (int i = 0; i < d; i++) {
    m = (m * c) % n;
  }
  return m;
}

int main() {
  int p = generate_prime(100, 1000);
  printf("p = %d\n", p);

  int q = generate_prime(100, 1000);
  printf("q = %d\n", q);

  int n, e, d;
  generate_keys(p, q, &n, &e, &d);
  printf("Public Key: n=%d, e=%d\n", n, e);
  printf("Private Key: d=%d\n", d);

  int m = 123;
  printf("Original Message: %d\n", m);

  int c = encrypt(m, e, n);
  printf("Encrypted Message: %d\n", c);

  int d_m = decrypt(c, d, n);
  printf("Decrypted Message: %d\n", d_m);

  return 0;
}