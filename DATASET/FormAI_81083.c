//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Public-Key Algorithm Implementation

// Key struct
typedef struct Key {
  int p;
  int q;
  int n;
  int phi;
  int e;
  int d;
} Key;

// Function to generate random prime numbers
int generatePrime()
{
  int num, i, isPrime;

  while (1)
  {
    num = rand() % 100 + 1;
    isPrime = 1;

    for (i = 2; i <= sqrt(num); i++)
    {
      if (num % i == 0)
      {
        isPrime = 0;
        break;
      }
    }

    if (isPrime)
    {
      return num;
    } 
  }
}

// Function to calculate the greatest common divisor
int gcd(int a, int b)
{
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

// Function to generate the key
Key generateKey()
{
  Key key;

  // Generate two random prime numbers
  key.p = generatePrime();
  key.q = generatePrime();

  key.n = key.p * key.q;
  key.phi = (key.p - 1) * (key.q - 1);

  // Find an integer e such that gcd(phi, e) = 1 (1 < e < phi)
  do {
    key.e = rand() % (key.phi - 2) + 2;
  } while (gcd(key.phi, key.e) != 1);

  // Find an integer d such that (d * e) % phi = 1
  int k = 1;
  while (((k * key.phi) + 1) % key.e != 0)
  {
    k++;
  }
  key.d = ((k * key.phi) + 1) / key.e;

  return key;
}

// Function to encrypt the message
void encrypt(int message[], int n, int e, int encrypted[])
{
  for (int i = 0; i < n; i++)
  {
    encrypted[i] = (int) pow(message[i], e) % n;
  }
}

// Function to decrypt the message
void decrypt(int encrypted[], int n, int d, int decrypted[])
{
  for (int i = 0; i < n; i++)
  {
    decrypted[i] = (int) pow(encrypted[i], d) % n;
  }
}

int main()
{
  int message[] = {4, 8, 15, 16, 23, 42};
  int n = sizeof(message) / sizeof(int);

  printf("Original message: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", message[i]);
  }
  printf("\n");

  Key key = generateKey();
  printf("Public key (e, n): (%d, %d)\n", key.e, key.n);
  printf("Private key (d, n): (%d, %d)\n", key.d, key.n);

  int encrypted[n];
  int decrypted[n];

  encrypt(message, key.n, key.e, encrypted);

  printf("Encrypted message: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", encrypted[i]);
  }
  printf("\n");

  decrypt(encrypted, key.n, key.d, decrypted);

  printf("Decrypted message: ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", decrypted[i]);
  }
  printf("\n");

  return 0;
}