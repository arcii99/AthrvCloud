//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to Encrypt given string using XOR 
void encrypt(char *string, char *key) {
  int stringLen = strlen(string), keyLen = strlen(key), i, j = 0;
  for (i = 0; i < stringLen; i++) {
    string[i] = string[i] ^ key[j];
    j++;
    if (j == keyLen) {
      j = 0;
    }
  }
}
//Function to Decrypt string using XOR
void decrypt(char *string, char *key) {
  int stringLen = strlen(string), keyLen = strlen(key), i, j = 0;
  for (i = 0; i < stringLen; i++) {
    string[i] = string[i] ^ key[j];
    j++;
    if (j == keyLen) {
      j = 0;
    }
  }
}

int main() {
  char string[100], key[100];
  printf("Enter a string to encrypt: ");
  scanf("%s", & string);
  printf("Enter a key to encrypt the string: ");
  scanf("%s", & key);
  encrypt(string, key);
  printf("Encrypted string: %s", string);
  decrypt(string, key);
  printf("\nDecrypted string: %s", string);
  return 0;
}