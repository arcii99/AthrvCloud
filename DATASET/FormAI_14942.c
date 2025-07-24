//FormAI DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[] = "Romeo, Romeo, wherefore art thou Romeo?";
  char encrypted_message[51];
  char key[] = "juliet";

  int message_length = strlen(message);
  int key_length = strlen(key);
  int i, j;

  printf("Original message: %s\n", message);

  // encryption
  for (i = 0, j = 0; i < message_length; i++, j++) {
    if (j == key_length) {
      j = 0;
    }

    encrypted_message[i] = ((message[i] + key[j]) % 26) + 'a';
  }
  encrypted_message[i] = '\0';

  printf("Encrypted message: %s\n", encrypted_message);

  // decryption
  for (i = 0, j = 0; i < message_length; i++, j++) {
    if (j == key_length) {
      j = 0;
    }

    message[i] = (((encrypted_message[i] - key[j]) + 26) % 26) + 'a';
  }
  message[i] = '\0';

  printf("Decrypted message: %s\n", message);

  return 0;
}