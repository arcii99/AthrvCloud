//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include <stdio.h>

int main() {
  printf("OMG! I just created a public-key algorithm implementation program!\n");

  // Generate keys
  int p = 23; // Prime number p
  int g = 5; // Generator g
  int secretA = 6; // Secret key for Alice
  int secretB = 15; // Secret key for Bob
  int publicA = 1; // Alice's public key
  int publicB = 1; // Bob's public key
  
  // Calculate public keys
  for (int i = 0; i < secretA; i++) {
    publicA = (publicA * g) % p;
  }

  for (int i = 0; i < secretB; i++) {
    publicB = (publicB * g) % p;
  }

  printf("Alice's public key: %d\n", publicA);
  printf("Bob's public key: %d\n", publicB);

  // Calculate shared secret
  int secretSharedA = 1;
  int secretSharedB = 1;

  for (int i = 0; i < secretA; i++) {
    secretSharedA = (secretSharedA * publicB) % p;
  }

  for (int i = 0; i < secretB; i++) {
    secretSharedB = (secretSharedB * publicA) % p;
  }

  printf("Alice's shared secret: %d\n", secretSharedA);
  printf("Bob's shared secret: %d\n", secretSharedB);

  printf("WOW! I can't believe it worked!\n");

  return 0;
}