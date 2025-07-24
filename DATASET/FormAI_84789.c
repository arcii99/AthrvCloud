//FormAI DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

char* encrypt(char input[]) {
  char* output = malloc(sizeof(char) * MAX_LENGTH);
  int len = strlen(input);
  
  for (int i = 0; i < len; i++) {
    output[i] = input[i] + 3;
  }
  
  return output;
}

char* decrypt(char input[]) {
  char* output = malloc(sizeof(char) * MAX_LENGTH);
  int len = strlen(input);
  
  for (int i = 0; i < len; i++) {
    output[i] = input[i] - 3;
  }
  
  return output;
}

int main() {
  char input[MAX_LENGTH];
  char* encrypted;
  char* decrypted;
  
  printf("Enter a string to encrypt: ");
  fgets(input, MAX_LENGTH, stdin);
  
  encrypted = encrypt(input);
  printf("Encrypted string: %s\n", encrypted);
  
  decrypted = decrypt(encrypted);
  printf("Decrypted string: %s\n", decrypted);
  
  free(encrypted);
  free(decrypted);
  
  return 0;
}