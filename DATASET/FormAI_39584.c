//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* plaintext, int shift) {
  int length = strlen(plaintext);
  char* ciphertext = malloc(length * sizeof(char));
  for(int i = 0; i < length; i++) {
    char c = plaintext[i];
    if(c >= 'a' && c <= 'z') { // lowercase letter
      c = (((c - 'a') + shift) % 26) + 'a';
    } else if (c >= 'A' && c <= 'Z') { // uppercase letter
      c = (((c - 'A') + shift) % 26) + 'A';
    }
    ciphertext[i] = c;
  }
  return ciphertext;
}

char* decrypt(char* ciphertext, int shift) {
  return encrypt(ciphertext, 26 - shift);
}

int main() {
  char* plaintext = "The end of the world is here";
  printf("Plaintext: %s\n", plaintext);
  
  int shift = 5; // arbitrary number for encryption
  char* ciphertext = encrypt(plaintext, shift);
  printf("Ciphertext: %s\n", ciphertext);
  
  char* decrypted = decrypt(ciphertext, shift);
  printf("Decrypted: %s\n", decrypted);
  free(ciphertext);
  free(decrypted);
  return 0;
}