//FormAI DATASET v1.0 Category: modern Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *output, char *key) {
  int i;
  int length = strlen(input);
  int key_length = strlen(key);
  
  for (i = 0; i < length; i++) {
    output[i] = input[i] ^ key[i % key_length];
  }
}

int main() {
  char input[100];
  char output[100];
  char key[100];
  
  // get user input
  printf("Enter a string to encrypt: ");
  fgets(input, sizeof(input), stdin);
  
  // get encryption key
  printf("Enter an encryption key: ");
  fgets(key, sizeof(key), stdin);
  
  // encrypt the input string
  encrypt(input, output, key);
  
  // print the encrypted string
  printf("\nEncrypted string: %s\n", output);
  
  // decrypt the encrypted string
  encrypt(output, input, key);
  
  // print the decrypted string
  printf("\nDecrypted string: %s\n", input);
  
  return 0;
}