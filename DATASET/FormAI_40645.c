//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// generate a random prime number
int gen_prime(int limit) {
  int num, flag = 0;
  while (1) {
    num = rand() % limit;
    if (num > 1) {
      for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        return num;
      }
      flag = 0;
    }
  }
}

// find GCD of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a%b);
}

// calculate the public key
int get_public_key(int prime1, int prime2) {
  int n = prime1 * prime2; // calculate the modulus
  int phi = (prime1 - 1) * (prime2 - 1); // calculate phi(n)
  // find a number e, such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
  int e;
  for (int i = 2; i < phi; i++) {
    if (gcd(i, phi) == 1) {
      e = i;
      break;
    }
  }
  return e;
}

// calculate the private key
int get_private_key(int prime1, int prime2, int public_key) {
  int phi = (prime1 - 1) * (prime2 - 1); // calculate phi(n)
  int d = 1;
  // find a number d, such that d*e mod phi(n) = 1
  // i.e., d is the modular multiplicative inverse of e
  while (1) {
    if ((d*public_key) % phi == 1) {
      break;
    }
    d++;
  }
  return d;
}

int main() {
  srand(time(NULL));
  // generate two random prime numbers
  int prime1 = gen_prime(50);
  int prime2 = gen_prime(50);
  printf("Prime numbers: %d, %d\n", prime1, prime2);
  
  // calculate public and private keys
  int public_key = get_public_key(prime1, prime2);
  int private_key = get_private_key(prime1, prime2, public_key);
  printf("Public key: %d, Private key: %d\n", public_key, private_key);

  // message to be encrypted
  int num = 7;
  printf("Original number: %d\n", num);

  // encryption
  int encrypted = (int)(pow(num, public_key)) % (prime1 * prime2);
  printf("Encrypted number: %d\n", encrypted);

  // decryption
  int decrypted = (int)(pow(encrypted, private_key)) % (prime1 * prime2);
  printf("Decrypted number: %d\n", decrypted);

  return 0;
}