//FormAI DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {
  char str[1000];
  int key;
  printf("Welcome to the Modern Encryption program! Enter a string to encrypt (max 1000 characters): ");
  scanf("%[^\n]%*c", str);
  printf("Enter a key to encrypt the string (1-26): ");
  scanf("%d", &key);

  //Encryption starts here
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = ((str[i] - 'a') + key) % 26 + 'a';
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = ((str[i] - 'A') + key) % 26 + 'A';
    }
  }
  printf("\nEncrypted string: %s\n", str);
  
  //Decryption starts here
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = ((str[i] - 'a') - key + 26) % 26 + 'a';
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = ((str[i] - 'A') - key + 26) % 26 + 'A';
    }
  }
  printf("Decrypted string: %s", str);
  
  return 0;
}