//FormAI DATASET v1.0 Category: modern Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char* plain_text, char* encrypted_text);
void decrypt(char* encrypted_text, char* decrypted_text);

int main(void) {

  char plain_text[100] = "Hello, World!";
  char encrypted_text[100], decrypted_text[100];

  srand(time(NULL)); // Seed the random number generator

  encrypt(plain_text, encrypted_text); // Encrypt the plain text
  decrypt(encrypted_text, decrypted_text); // Decrypt the encrypted text

  printf("Plain Text: %s\n", plain_text);
  printf("Encrypted Text: %s\n", encrypted_text);
  printf("Decrypted Text: %s\n", decrypted_text);

  return 0;
}

void encrypt(char* plain_text, char* encrypted_text) {

  int key, i, j, len;

  len = strlen(plain_text);

  // Generate a random key value between 1 and 26
  key = rand() % 26 + 1;

  // Loop through each character of the plain text
  for(i = 0; i < len; i++) {

    // Change the character to a number between 0 and 25
    plain_text[i] -= 'a';

    // Encrypt the character using the key value
    plain_text[i] = (char)((plain_text[i] + key) % 26);

    // Change the character back to its original value
    plain_text[i] += 'a';

  }

  // Add the key value at the beginning of the encrypted text
  encrypted_text[0] = key + '0';

  j = 1;

  // Add each character of the encrypted text to the string
  for(i = 0; i < len; i++) {

    encrypted_text[j] = plain_text[i];

    j++;

  }

  encrypted_text[j] = '\0';

}

void decrypt(char* encrypted_text, char* decrypted_text) {

  int key, i, j, len;

  len = strlen(encrypted_text);

  // Get the key value from the first character of the encrypted text
  key = encrypted_text[0] - '0';

  j = 0;

  // Loop through each character of the encrypted text
  for(i = 1; i < len; i++) {

    // Change the character to a number between 0 and 25
    encrypted_text[i] -= 'a';

    // Decrypt the character using the key value
    encrypted_text[i] = (char)((encrypted_text[i] - key + 26) % 26);

    // Change the character back to its original value
    encrypted_text[i] += 'a';

    decrypted_text[j] = encrypted_text[i];

    j++;

  }

  decrypted_text[j] = '\0';

}