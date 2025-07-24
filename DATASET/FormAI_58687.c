//FormAI DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to perform encryption
void encrypt(char *message, char *cipher, int key) {
   int i;
   for(i=0;i<strlen(message);i++) {
      cipher[i] = (message[i] + key) % 26 + 'A';
   }
   cipher[i] = '\0';
}

//function to perform decryption
void decrypt(char *cipher, char *plaintext, int key) {
   int i;
   for(i=0; i<strlen(cipher); i++) {
      plaintext[i] = (cipher[i] - key + 26) % 26 + 'A';
   }
   plaintext[i] = '\0';
}

int main() {
   char message[100], cipher[100], plaintext[100];
   int key;
   
   printf("Enter the message to encrypt: ");
   fgets(message, sizeof(message), stdin);
   
   printf("Enter the encryption key: ");
   scanf("%d", &key);
   
   encrypt(message, cipher, key);
   printf("Encrypted message: %s\n", cipher);
   
   decrypt(cipher, plaintext, key);
   printf("Decrypted message: %s\n", plaintext);
   
   return 0;
}