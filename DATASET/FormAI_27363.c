//FormAI DATASET v1.0 Category: Modern Encryption ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
  char message[1000], key[1000];
  int i, j;

  // Get the message from user
  printf("Enter the message to be encrypted: ");
  scanf("%[^\n]", message);

  // Get the key from user
  printf("Enter the key to be used for encryption: ");
  scanf(" %[^\n]", key);

  // Calculate the length of message and key
  int message_len = strlen(message);
  int key_len = strlen(key);

  // Generate the encryption key
  char encryption_key[message_len];
  for (i = 0, j = 0; i < message_len; i++, j++) {
    if (j == key_len) {
      j = 0;
    }

    encryption_key[i] = key[j];
  }

  encryption_key[i] = '\0';

  // Encrypt the message using the encryption key
  char encrypted_message[message_len];
  for (i = 0; i < message_len; i++) {
    encrypted_message[i] = ((message[i] + encryption_key[i]) % 26) + 'A';
  }

  encrypted_message[i] = '\0';

  // Print the encrypted message
  printf("\nEncrypted message: %s\n", encrypted_message);

  return 0;
}