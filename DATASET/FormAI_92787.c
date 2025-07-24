//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

/* This program demonstrates the use of bitwise operations 
   to encrypt and decrypt a message */

int main() {
  unsigned int key = 0xfaceb00c; // secret key for encryption/decryption
  char message[100]; // message to be encrypted/decrypted

  // get message from user
  printf("Enter message to be encrypted/decrypted: ");
  fgets(message, 100, stdin);
  
  // encrypt message using XOR
  for (int i = 0; i < strlen(message); i++) {
    message[i] = message[i] ^ (key & 0xff); // XOR each character with last 8 bits of key
    key = key >> 8 | key << 24; // rotate key to the left by 8 bits
  }

  printf("Encrypted message: %s\n", message);

  // decrypt message using XOR
  for (int i = 0; i < strlen(message); i++) {
    message[i] = message[i] ^ (key & 0xff); // XOR each character with last 8 bits of key
    key = key >> 8 | key << 24; // rotate key to the left by 8 bits
  }

  printf("Decrypted message: %s\n", message);

  return 0;
}