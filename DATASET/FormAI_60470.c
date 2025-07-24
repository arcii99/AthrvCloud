//FormAI DATASET v1.0 Category: modern Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 4 // Encryption key

void encrypt(char* message) {
  int message_length = strlen(message);

  // Iterate over each character of the message
  for (int i = 0; i < message_length; i++) {
    // If the character is not a space, apply the encryption logic
    if (message[i] != ' ') {
      message[i] = message[i] + KEY;
    }
  }
}

void decrypt(char* message) {
  int message_length = strlen(message);

  // Iterate over each character of the message
  for (int i = 0; i < message_length; i++) {
    // If the character is not a space, apply the decryption logic
    if (message[i] != ' ') {
      message[i] = message[i] - KEY;
    }
  }
}

int main() {
  char message[100];

  printf("Enter message to encrypt: ");
  fgets(message, sizeof(message), stdin);

  // Remove newline character from the message
  message[strcspn(message, "\n")] = 0;

  encrypt(message);
  printf("Encrypted message: %s\n", message);

  decrypt(message);
  printf("Decrypted message: %s\n", message);

  return 0;
}