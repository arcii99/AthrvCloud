//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int n;
   int e;
} pub_key;

typedef struct {
   int n;
   int d;
} priv_key;

int gcd(int a, int b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

int co_prime(int a, int b) {
   return gcd(a, b) == 1;
}

pub_key get_public_key(int n) {
   int e = 2;
   while (!co_prime(n, e)) e++;
   pub_key key = {n, e};
   return key;
}

priv_key get_private_key(int n, int e) {
   int d = rand() % 1000;
   while (((d * e) % n) != 1) d++;
   priv_key key = {n, d};
   return key;
}

int encrypt(int m, pub_key key) {
   int c = 1;
   for (int i = 0; i < key.e; i++)
      c = (c * m) % key.n;
   return c;
}

int decrypt(int c, priv_key key) {
   int m = 1;
   for (int i = 0; i < key.d; i++)
      m = (m * c) % key.n;
   return m;
}

int main() {
   printf("Welcome to the surrealist implementation of the Public-Key Algorithm!\n\n");

   // Generate public key
   int n = 55;
   pub_key pub = get_public_key(n);
   printf("Public Key:\n  n: %d\n  e: %d\n\n", pub.n, pub.e);

   // Generate private key
   priv_key priv = get_private_key(pub.n, pub.e);
   printf("Private Key:\n  n: %d\n  d: %d\n\n", priv.n, priv.d);

   // Encrypt message
   int m = 10;
   int c = encrypt(m, pub);
   printf("Message: %d\nEncrypted: %d\n\n", m, c);

   // Decrypt message
   int dec = decrypt(c, priv);
   printf("Decrypted: %d\n\n", dec);

   return 0;
}