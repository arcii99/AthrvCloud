//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRIVATE_KEY 299
#define PUBLIC_KEY 3
#define PRIME1 17
#define PRIME2 19

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main(int argc, char const *argv[]) {
  char message[100];
  int i, j, len, cipher[100], decrypted[100];
  int p = PRIME1, q = PRIME2, n, phi, e = PUBLIC_KEY, d = PRIVATE_KEY;

  while (gcd(e, (p - 1)*(q - 1)) != 1) {
    e++;
  }

  n = p * q;
  phi = (p - 1) * (q - 1);

  while ((d * e) % phi != 1) {
    d++;
  }

  printf("Enter the message: ");
  fgets(message, 100, stdin);
  len = strlen(message);

  for (i = 0; i < len; i++) {
    cipher[i] = (int)pow((double)message[i], e) % n;
  }

  printf("\nEncrypted Message: ");
  for (i = 0; i < len; i++) {
    printf("%d ", cipher[i]);
  }

  for (i = 0; i < len; i++) {
    decrypted[i] = (int)pow((double)cipher[i], d) % n;
  }

  printf("\nDecrypted Message: ");
  for (i = 0; i < len; i++) {
    printf("%c", decrypted[i]);
  }

  return 0;
}