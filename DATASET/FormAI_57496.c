//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char message[100]; // User message to be encrypted
  char password[50]; // Password used to encrypt message
  char encrypted[100]; // Encrypted message
  int i;

  // Introduction
  printf("Welcome to the Super Secure C File Encryptor! Please follow the prompts to encrypt your message.\n");

  // Get message from user
  printf("Enter message to be encrypted:\n");
  fgets(message, sizeof(message), stdin);

  // Get password from user
  printf("Enter password to encrypt message with:\n");
  fgets(password, sizeof(password), stdin);

  // Encrypt the message using the password
  for(i = 0; i < strlen(message); i++) {
    encrypted[i] = message[i] ^ password[i % strlen(password)];
  }

  // Output the encrypted message
  printf("Your message has been encrypted! Behold:\n");
  for(i = 0; i < strlen(message); i++) {
    printf("%02x", encrypted[i]);
  }
  printf("\n");

  // Exit the program
  return 0;
}