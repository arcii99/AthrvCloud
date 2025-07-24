//FormAI DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>

int main() {
  char text[100];
  int key;

  // Input the text to be encrypted
  printf("Enter the text to encrypt: ");
  fgets(text, 100, stdin);

  // Input the encryption key
  printf("Enter the encryption key: ");
  scanf("%d", &key);

  // Encrypt the text
  int i = 0;
  while (text[i] != '\0') {
    // Apply the encryption formula
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] = (text[i] - 'a' + key) % 26 + 'a';
    } else if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] = (text[i] - 'A' + key) % 26 + 'A';
    }
    i++;
  }

  // Print the encrypted text
  printf("Encrypted text: %s", text);

  return 0;
}