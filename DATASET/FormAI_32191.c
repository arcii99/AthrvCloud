//FormAI DATASET v1.0 Category: Modern Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function declarations
void generateRSAKeys(int*, int*, int*);
int encryptMessage(int, int, int);
int decryptMessage(int, int, int);
int generateRandomPrime(int, int);
int isPrime(int);

int main() {
  int p, q, n, phi, e, d;
  char message[100];
  int encryptedMessage[100];
  int decryptedMessage[100];

  // Generate RSA keys
  generateRSAKeys(&p, &q, &n);
  phi = (p - 1) * (q - 1);
  e = generateRandomPrime(2, phi - 1);
  d = encryptMessage(e, phi, 1);

  printf("Enter message to encrypt: ");
  fgets(message, 100, stdin);
  int messageLength = strlen(message);

  // Encrypt message
  for (int i = 0; i < messageLength; i++) {
    encryptedMessage[i] = encryptMessage(message[i], e, n);
  }

  // Decrypt message
  for (int i = 0; i < messageLength; i++) {
    decryptedMessage[i] = decryptMessage(encryptedMessage[i], d, n);
  }

  printf("\nEncrypted message is: ");
  for (int i = 0; i < messageLength; i++) {
    printf("%d ", encryptedMessage[i]);
  }

  printf("\nDecrypted message is: ");
  for (int i = 0; i < messageLength; i++) {
    printf("%c", decryptedMessage[i]);
  }

  return 0;
}

// Function to generate RSA keys
void generateRSAKeys(int* pPtr, int* qPtr, int* nPtr) {
  srand(time(NULL));
  int minPrime = 100;
  int maxPrime = 999;
  int prime1 = generateRandomPrime(minPrime, maxPrime);
  int prime2 = generateRandomPrime(minPrime, maxPrime);

  while (prime1 == prime2) {
    prime2 = generateRandomPrime(minPrime, maxPrime);
  }

  *pPtr = prime1;
  *qPtr = prime2;
  *nPtr = prime1 * prime2;
}

// Function to encrypt message
int encryptMessage(int message, int key, int modulus) {
  int result = 1;
  message = message % modulus;

  while (key > 0) {
    if (key % 2 == 1) {
      result = (result * message) % modulus;
    }

    key = key / 2;
    message = (message * message) % modulus;
  }

  return result;
}

// Function to decrypt message
int decryptMessage(int message, int key, int modulus) {
  int result = 1;
  message = message % modulus;

  while (key > 0) {
    if (key % 2 == 1) {
      result = (result * message) % modulus;
    }

    key = key / 2;
    message = (message * message) % modulus;
  }

  return result;
}

// Function to generate random prime number
int generateRandomPrime(int min, int max) {
  int random = rand() % (max - min + 1) + min;

  while (!isPrime(random)) {
    random = rand() % (max - min + 1) + min;
  }

  return random;
}

// Function to check if number is prime
int isPrime(int number) {
  if (number <= 1) {
    return 0;
  }

  for (int i = 2; i <= number / 2; i++) {
    if (number % i == 0) {
      return 0;
    }
  }

  return 1;
}