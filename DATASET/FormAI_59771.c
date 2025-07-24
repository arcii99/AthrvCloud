//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//function to check if a number is prime or not
int isPrime(int num) {
  int i;
  for(i = 2; i <= sqrt(num); i++) {
    if(num % i == 0)
      return 0;
  }
  return 1;
}

//function to generate a random prime number
int generatePrime() {
  int num = rand() % 1000;
  while(!isPrime(num)) {
    num = rand() % 1000;
  }
  return num;
}

//function to calculate GCD of two numbers
int GCD(int a, int b) {
  if(b == 0) return a;
  return GCD(b, a % b);
}

//function to calculate the modular inverse of a number
int findModularInverse(int a, int m) {
  int m0 = m, t, q;
  int x0 = 0, x1 = 1;

  if (m == 1) return 0;

  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  
  if (x1 < 0) x1 += m0;

  return x1;
}

//function to encrypt a message using the public key (e, n)
int encrypt(int message, int e, int n) {
  int encrypted = (int) pow(message, e);
  encrypted %= n;
  return encrypted;
}

//function to decrypt a message using the private key (d, n)
int decrypt(int message, int d, int n) {
  int decrypted = (int) pow(message, d);
  decrypted %= n;
  return decrypted;
}

int main() {
  srand(time(NULL));

  //generate two distinct prime numbers p and q
  int p = generatePrime();
  int q = generatePrime();
  while(p == q) {
    q = generatePrime();
  }

  //calculate n and phi(n)
  int n = p * q;
  int phi = (p - 1) * (q - 1);

  //choose a public key e such that 1 < e < phi(n) and GCD(e, phi(n)) = 1
  int e;
  do {
    e = rand() % (phi - 1) + 2;
  } while(GCD(e, phi) != 1);

  //calculate the private key d using the modular inverse of e and phi(n)
  int d = findModularInverse(e, phi);

  //print out the public and private keys
  printf("Public Key (e,n): (%d,%d)\n", e, n);
  printf("Private Key (d,n): (%d,%d)\n", d, n);

  //ask user for a message to encrypt
  int message;
  printf("Enter a message to encrypt: ");
  scanf("%d", &message);

  //encrypt the message using the public key (e, n)
  int encrypted = encrypt(message, e, n);
  printf("Encrypted Message: %d\n", encrypted);

  //decrypt the message using the private key (d, n)
  int decrypted = decrypt(encrypted, d, n);
  printf("Decrypted Message: %d\n", decrypted);

  return 0;
}