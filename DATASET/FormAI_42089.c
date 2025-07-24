//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME1 17
#define PRIME2 19

int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int generatePublicKey(int p, int q) {
  int n = p * q, e = 2, phi = (p - 1) * (q - 1);
  while (e < phi) {
    if (gcd(e, phi) == 1)
      break;
    else
      e++;
  }
  return e;
}

int generatePrivateKey(int p, int q, int e) {
  int n = p * q, phi = (p - 1) * (q - 1), d = 0;
  while (d < phi) {
    if ((e * d) % phi == 1)
      break;
    else
      d++;
  }
  return d;
}

int encrypt(int plaintext, int e, int n) {
  int ciphertext = plaintext;
  for (int i = 1; i < e; i++) {
    ciphertext *= plaintext;
    ciphertext %= n;
  }
  return ciphertext;
}

int decrypt(int ciphertext, int d, int n) {
  int plaintext = ciphertext;
  for (int i = 1; i < d; i++) {
    plaintext *= ciphertext;
    plaintext %= n;
  }
  return plaintext;
}

int main() {

  int p = PRIME1, q = PRIME2;
  int n = p * q;
  int e = generatePublicKey(p, q);
  int d = generatePrivateKey(p, q, e);

  char message[1000];
  printf("Enter the message to be encrypted:\n");
  fgets(message, 1000, stdin);
  message[strcspn(message, "\n")] = '\0';

  printf("Plaintext: %s\n", message);
  printf("Public Key: (%d, %d)\n", e, n);
  printf("Private Key: (%d, %d)\n", d, n);

  int encryptedMessage[strlen(message)];
  int decryptedMessage[strlen(message)];
  
  for (int i = 0; i < strlen(message); i++) {
    int m = (int)message[i];
    encryptedMessage[i] = encrypt(m, e, n);
    decryptedMessage[i] = decrypt(encryptedMessage[i], d, n);
  }

  printf("\nEncrypted Message: ");
  for (int i = 0; i < strlen(message); i++) {
    printf("%d ", encryptedMessage[i]);
  }

  printf("\nDecrypted Message: ");
  for (int i = 0; i < strlen(message); i++) {
    printf("%c", (char)decryptedMessage[i]);
  }

  printf("\n\nEncryption and Decryption Successful!\n");

  return 0;
}