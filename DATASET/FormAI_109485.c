//FormAI DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *key){

  int plaintext_len = strlen(plaintext);
  int key_len = strlen(key);

  int i, j;
  char cipher[plaintext_len];
  
  // Encryption algorithm
  for(i = 0, j = 0; i < plaintext_len; i++, j++){
    if(j == key_len) j = 0;
  
    cipher[i] = ((plaintext[i] + key[j]) % 26) + 'A';
  }

  printf("Encrypted text: %s\n", cipher);

}

int main(void) {

  char plaintext[1000];
  char key[1000];
  
  printf("Enter the plaintext to be encrypted: ");
  fgets(plaintext, 1000, stdin);

  printf("Enter the encryption key: ");
  fgets(key, 1000, stdin);
  
  // Removing trailing newline character
  plaintext[strcspn(plaintext, "\n")] = 0;
  key[strcspn(key, "\n")] = 0;
  
  encrypt(plaintext, key);
  
  return 0;

}