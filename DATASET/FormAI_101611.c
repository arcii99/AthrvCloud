//FormAI DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This is a brave program that demonstrates a unique C encryption technique.
 * 
 * In this technique, we will take the input message and convert each character to its decimal
 * representation, then perform a bitwise XOR operation with a secret key. The resulting encrypted
 * byte values will be stored in a buffer and printed to the console.
 * 
 * To decrypt the message, the process is simply reversed: XOR the encrypted bytes with the secret key
 * to obtain the original byte values, and then convert each byte back to its character representation.
 * 
 * Let's get started!
 */

int main() {
  char input[256];
  char output[256];
  char secret_key = 'Z'; // our secret key
  int i;

  // prompt the user for an input message
  printf("Enter message to encrypt:\n");
  fgets(input, sizeof(input), stdin);

  // encrypt the input message
  for (i = 0; i < strlen(input); i++) {
    // convert the character to its decimal representation
    int decimal = (int) input[i];

    // perform a bitwise XOR operation with the secret key
    int encrypted = decimal ^ (int) secret_key;

    // store the encrypted byte value in the output buffer
    output[i] = (char) encrypted;
  }

  // print the encrypted message to the console
  printf("Encrypted message: ");
  for (i = 0; i < strlen(input); i++) {
    printf("%d ", (int) output[i]);
  }
  printf("\n");

  // decrypt the message
  printf("Decrypting message...\n");
  for (i = 0; i < strlen(input); i++) {
    // perform a bitwise XOR operation with the secret key to obtain the original byte value
    int decrypted = (int) output[i] ^ (int) secret_key;

    // convert the decrypted byte back to its character representation
    printf("%c", (char) decrypted);
  }
  printf("\n");

  return 0;
}