//FormAI DATASET v1.0 Category: Encryption ; Style: inquisitive
#include <stdio.h>
#include <string.h>

// Function to perform encryption
void encrypt(char *str, int key) {
  int len = strlen(str);
  for(int i = 0; i < len; i++) {
    str[i] += key;   // add key to ASCII value of each character in string
  }
}

// Function to perform decryption
void decrypt(char *str, int key) {
  int len = strlen(str);
  for(int i = 0; i < len; i++) {
    str[i] -= key;   // subtract key from ASCII value of each character in string
  }
}

int main() {
  char message[100];
  int key;
  
  printf("Enter message to encrypt: ");
  fgets(message, sizeof(message), stdin);
  message[strcspn(message, "\n")] = '\0';   // remove newline character from fgets
  
  printf("Enter encryption key (integer): ");
  scanf("%d", &key);
  
  encrypt(message, key);   // encrypt message
  
  printf("\nEncrypted message: %s\n", message);
  
  decrypt(message, key);   // decrypt message
  
  printf("Decrypted message: %s\n", message);
  
  return 0;
}