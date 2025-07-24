//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>

// Define functions for encryption and decryption
int encrypt(int message, int key);
int decrypt(int ciphertext, int key);

// Main function
int main() {

  // Define variables
  int plaintext = 10;
  int public_key = 5;
  int private_key = 11;

  // Encryption
  int ciphertext = encrypt(plaintext, public_key);
  printf("Ciphertext: %d\n", ciphertext);

  // Decryption
  int decrypted_text = decrypt(ciphertext, private_key);
  printf("Decrypted text: %d\n", decrypted_text);

  return 0;
}

// Function to encrypt message using public key
int encrypt(int message, int key) {
  return message * key;
}

// Function to decrypt ciphertext using private key
int decrypt(int ciphertext, int key) {
  return ciphertext / key;
}