//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to C Encryption Program!\n");
  printf("Please enter a string to encrypt:\n");
  char original_str[100];
  scanf("%s", original_str);
  
  char encrypted_str[100];
  int key;
  printf("Please enter an encryption key (number between 1 to 26):\n");
  scanf("%d", &key);

  // Encryption Logic
  for (int i = 0; original_str[i] != '\0'; i++) {
    char c = original_str[i];
    if (c >= 'a' && c <= 'z') {
      c = (c - 'a' + key) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
      c = (c - 'A' + key) % 26 + 'A';
    }
    encrypted_str[i] = c;
  }
  encrypted_str[strlen(original_str)] = '\0';

  printf("Encrypted string: %s\n", encrypted_str);
  
  // Decryption Logic
  char decrypted_str[100];
  for (int i = 0; encrypted_str[i] != '\0'; i++) {
    char c = encrypted_str[i];
    if (c >= 'a' && c <= 'z') {
      c = (c - 'a' - key + 26) % 26 + 'a';
    } else if (c >= 'A' && c <= 'Z') {
      c = (c - 'A' - key + 26) % 26 + 'A';
    }
    decrypted_str[i] = c;
  }
  decrypted_str[strlen(encrypted_str)] = '\0';

  printf("Decrypted string: %s\n", decrypted_str);

  return 0;
}