//FormAI DATASET v1.0 Category: Modern Encryption ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
  char plain_text[100];
  char key[100];
  char cipher_text[100];
  int i, j;

  printf("Enter the plain text: ");
  scanf("%s", plain_text);

  printf("Enter the encryption key: ");
  scanf("%s", key);

  // Determine the length of the key.
  int key_length = strlen(key);

  // Determine the length of the plain_text.
  int plain_text_length = strlen(plain_text);

  // Loop through each character of the plain_text.
  for (i = 0, j = 0; i < plain_text_length; i++, j++) {
    // If we have reached the end of the key, start again from the beginning.
    if (j == key_length) {
      j = 0;
    }

    // Encrypt each character of the plain_text using the corresponding character of the key.
    cipher_text[i] = ((plain_text[i] + key[j]) % 26) + 'a';
  }

  printf("The plain text is: %s\n", plain_text);
  printf("The encryption key is: %s\n", key);
  printf("The cipher text is: %s\n", cipher_text);

  return 0;
}