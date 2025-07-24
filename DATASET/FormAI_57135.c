//FormAI DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[100];
  char secret_key[100];
  int key_length, message_length, i;

  printf("Enter the secret key: ");
  scanf("%s", secret_key);
  key_length = strlen(secret_key);

  printf("Enter the message: ");
  scanf("%s", message);
  message_length = strlen(message);

  // XOR encryption algorithm
  for (i=0; i<message_length; i++) {
    message[i] = message[i] ^ secret_key[i % key_length];
  }

  printf("Encrypted message: %s\n", message);

  // XOR decryption algorithm
  for (i=0; i<message_length; i++) {
    message[i] = message[i] ^ secret_key[i % key_length];
  }

  printf("Decrypted message: %s\n", message);

  return 0;
}