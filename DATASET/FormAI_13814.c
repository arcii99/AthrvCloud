//FormAI DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These constants are used for initializing the encryption
// and decryption keys
const int ENCRYPTION_KEY = 7;
const int DECRYPTION_KEY = -7;

// Encrypts the given message using the encryption key
void encrypt(char *message, char *encrypted) {
  int i;
  for (i = 0; i < strlen(message); i++) {
    encrypted[i] = (char)((int)message[i] + ENCRYPTION_KEY);
  }
  encrypted[i] = '\0'; // Null-terminate the encrypted string
}

// Decrypts the given encrypted message using the decryption key
void decrypt(char *encrypted, char *decrypted) {
  int i;
  for (i = 0; i < strlen(encrypted); i++) {
    decrypted[i] = (char)((int)encrypted[i] + DECRYPTION_KEY);
  }
  decrypted[i] = '\0'; // Null-terminate the decrypted string
}

int main() {
  char message[100], encrypted[100], decrypted[100];
  
  // Get the message from the user
  printf("Enter message to encrypt: ");
  fgets(message, 100, stdin);
  message[strcspn(message, "\n")] = '\0'; // Remove the newline character
  
  // Encrypt the message and display the encrypted string
  encrypt(message, encrypted);
  printf("Encrypted message: %s\n", encrypted);
  
  // Decrypt the encrypted message and display the decrypted string
  decrypt(encrypted, decrypted);
  printf("Decrypted message: %s\n", decrypted);

  return 0;
}