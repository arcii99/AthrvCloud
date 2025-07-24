//FormAI DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, char *key);
void decrypt(char *ciphertext, char *key);

int main() {
   char plaintext[100], key[100], ciphertext[100];
   
   printf("Enter plaintext: ");
   scanf("%s", plaintext);
   
   printf("Enter key: ");
   scanf("%s", key);

   // Encrypt plaintext using key
   encrypt(plaintext, key);
   printf("Encrypted text: %s\n", plaintext);

   // Decrypt ciphertext using key
   decrypt(plaintext, key);
   printf("Decrypted text: %s\n", plaintext);

   return 0;
}

void encrypt(char *plaintext, char *key) {
   int i;
   int keyLength = strlen(key);
   int plaintextLength = strlen(plaintext);
   
   for(i = 0; i < plaintextLength; ++i) {
      plaintext[i] = plaintext[i] ^ key[i % keyLength];
   }
}

void decrypt(char *ciphertext, char *key) {
   int i;
   int keyLength = strlen(key);
   int ciphertextLength = strlen(ciphertext);
   
   for(i = 0; i < ciphertextLength; ++i) {
      ciphertext[i] = ciphertext[i] ^ key[i % keyLength];
   }
}