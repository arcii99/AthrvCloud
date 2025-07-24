//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char key[26] = "bazinga";
  char message[100];
  
  printf("Hello, I am your friendly neighborhood encryption program!\n\n");
  printf("Please enter the message you want to encrypt (max length 100 chars):\n");
  fgets(message, 100, stdin);
  int messageLen = strlen(message) - 1;
  char encryptedMessage[messageLen]; 
  char decryptedMessage[messageLen];

  // Encryption
  for (int i=0; i<messageLen; i++) {
    if (message[i] >= 'a' && message[i] <= 'z') {
      encryptedMessage[i] = (char) ((message[i] + key[i % 7]) % 26 + 'a');
    } else if (message[i] >= 'A' && message[i] <= 'Z') {
      encryptedMessage[i] = (char) ((message[i] + key[i % 7]) % 26 + 'A');
    } else {
      encryptedMessage[i] = message[i];
    }
  }

  printf("\nYour encrypted message is:\n%s\n", encryptedMessage);

  // Decryption
  for (int i=0; i<messageLen; i++) {
    if (encryptedMessage[i] >= 'a' && encryptedMessage[i] <= 'z') {
      decryptedMessage[i] = (char) ((encryptedMessage[i] - key[i % 7] + 26) % 26 + 'a');
    } else if (encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z') {
      decryptedMessage[i] = (char) ((encryptedMessage[i] - key[i % 7] + 26) % 26 + 'A');
    } else {
      decryptedMessage[i] = encryptedMessage[i];
    }
  }

  printf("\nYour decrypted message is:\n%s\n", decryptedMessage);
  
  return 0;
}