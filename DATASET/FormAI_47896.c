//FormAI DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_LENGTH 100

void encrypt(char message[], char key[]);
void decrypt(char message[], char key[]);

int main() {
  char message[MAX_LENGTH];
  char key[MAX_LENGTH];
  
  printf("Enter message to encrypt: ");
  fgets(message, MAX_LENGTH, stdin);
  
  // Generate a random key
  srand(time(NULL));
  for(int i = 0; i < strlen(message); i++) {
    key[i] = (char)(rand() % 256);
  }
  
  encrypt(message, key);
  printf("Encrypted Message: %s\n", message);
  
  decrypt(message, key);
  printf("Decrypted Message: %s\n", message);
  
  return 0;
}

void encrypt(char message[], char key[]) {
  int len = strlen(message);
  
  for(int i = 0; i < len; i++) {
    message[i] ^= key[i];
  }
}

void decrypt(char message[], char key[]) {
  int len = strlen(message);
  
  for(int i = 0; i < len; i++) {
    message[i] ^= key[i];
  }
}