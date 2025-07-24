//FormAI DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
  printf("Welcome to the happiest C encryption program!\n");

  // Declare variables for encryption
  char message[100];
  char encrypted[100];
  int key = 5;

  // Ask the user for a message to encrypt
  printf("Please enter a message to encrypt: ");
  fgets(message, 100, stdin);

  // Loop through each character in the message and shift its ASCII value
  for (int i = 0; i < strlen(message); i++) {
    if (message[i] != ' ') {
      encrypted[i] = (message[i] - 32 + key) % 95 + 32;
    } else {
      encrypted[i] = ' ';
    }
  }

  // Print the encrypted message
  printf("Your encrypted message is: %s\n", encrypted);

  // Decrypt the message using the same key
  char decrypted[100];
  for (int i = 0; i < strlen(encrypted); i++) {
    if (encrypted[i] != ' ') {
      decrypted[i] = (encrypted[i] - 32 - key + 95) % 95 + 32;
    } else {
      decrypted[i] = ' ';
    }
  }

  // Print the decrypted message
  printf("Your decrypted message is: %s\n", decrypted);

  printf("Happy encrypting!\n");

  return 0;
}