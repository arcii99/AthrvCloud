//FormAI DATASET v1.0 Category: Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 256

char key[MAX_KEY_LENGTH];

char* encrypt(char* message);
char* decrypt(char* message);

int main() {
  srand(time(NULL));

  // Generate Random Key
  for (int i = 0; i < MAX_KEY_LENGTH; i++) {
    key[i] = rand() % 94 + 32; // ASCII Range [32, 126]
  }

  char message[100];
  printf("Enter message to encrypt: ");
  fgets(message, sizeof(message), stdin);
  message[strcspn(message, "\n")] = 0;

  printf("\nPlaintext: %s\n", message);

  char* cipher = encrypt(message);
  printf("Ciphertext: %s\n", cipher);

  char* plaintext = decrypt(cipher);
  printf("Decrypted Text: %s\n", plaintext);

  return 0;
}

char* encrypt(char* message) {
  int length = strlen(message);
  char* cipher = (char*) malloc((length + 1) * sizeof(char));
  cipher[length] = '\0';

  for (int i = 0; i < length; i++) {
    cipher[i] = message[i] ^ key[i % MAX_KEY_LENGTH];
  }

  return cipher;
}

char* decrypt(char* message) {
  int length = strlen(message);
  char* plaintext = (char*) malloc((length + 1) * sizeof(char));
  plaintext[length] = '\0';

  for (int i = 0; i < length; i++) {
    plaintext[i] = message[i] ^ key[i % MAX_KEY_LENGTH];
  }

  return plaintext; 
}