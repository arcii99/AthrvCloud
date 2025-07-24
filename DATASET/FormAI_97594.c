//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  // random key generation
  char key[26];
  for (int i = 0; i < 26; i++) {
    int r = rand() % (26 - i);
    key[i] = 'a' + r;
    for (int j = i; j > 0; j--) {
      if (key[j] < key[j - 1]) {
        char temp = key[j];
        key[j] = key[j - 1];
        key[j - 1] = temp;
      }
    }
  }
  printf("Randomly generated key: %s\n", key);

  // encryption of input message using the key
  char message[100];
  printf("Enter a message to encrypt: ");
  fgets(message, 100, stdin);
  int length = strlen(message);
  for (int i = 0; i < length; i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      message[i] = key[message[i] - 'a'];
    }
  }
  printf("Encrypted message: %s\n", message);

  // decryption of encrypted message using the key
  char decrypted[100];
  for (int i = 0; i < length; i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      for (int j = 0; j < 26; j++) {
        if (key[j] == message[i]) {
          decrypted[i] = 'a' + j;
          break;
        }
      }
    } else {
      decrypted[i] = message[i];
    }
  }
  printf("Decrypted message: %s\n", decrypted);

  return 0;
}