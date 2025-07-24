//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
/* 
  ROMEO: 
  O my Juliet, my love for thee is strong,
  And thus, I shall protect our messages from wrong.
  Let our words be guarded from prying eyes,
  Using cryptography that none shall surmise.

  JULIET:
  Sweet Romeo, thy passion is my delight,
  And I shall assist thee in thy cryptic fight.
  Together, let our love be ever secure,
  Using encryption that none shall procure.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

void pad_message(char* message, int len) {
  int padding = KEY_LENGTH - (len % KEY_LENGTH);
  for (int i = 0; i < padding; i++) {
    message[len + i] = padding;
  }
}

void encrypt(char* message, int len, unsigned char* key) {
  pad_message(message, len);

  for (int i = 0; i < len; i += KEY_LENGTH) {
    for (int j = 0; j < KEY_LENGTH && i + j < len; j++) {
      message[i + j] ^= key[j];
    }
  }
}

void decrypt(char* message, int len, unsigned char* key) {
  for (int i = 0; i < len; i += KEY_LENGTH) {
    for (int j = 0; j < KEY_LENGTH && i + j < len; j++) {
      message[i + j] ^= key[j];
    }
  }

  int padding = message[len - 1];
  message[len - padding] = '\0';
}

int main() {
  unsigned char key[KEY_LENGTH] = "RomeoAndJuliet";
  char message[1024] = "O Romeo, Romeo! wherefore art thou Romeo? Deny thy father and refuse thy name; Or, if thou wilt not, be but sworn my love, And I'll no longer be a Capulet.";

  int len = strlen(message);
  encrypt(message, len, key);
  printf("Encrypted message: %s\n", message);

  decrypt(message, len, key);
  printf("Decrypted message: %s\n", message);

  return 0;
}