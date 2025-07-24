//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char inputMessage[100] = {0};
   char encryptionKey[100] = {0};
   char encryptedMessage[100] = {0};
   int inputLength = 0, keyLength = 0, i = 0, j = 0;
   
   // Getting the input message and key from the user
   printf("Enter the message you want to encrypt: ");
   scanf("%[^\n]s", inputMessage);
   printf("Enter the encryption key: ");
   scanf("%s", encryptionKey);
   
   inputLength = strlen(inputMessage);
   keyLength = strlen(encryptionKey);
   
   // Encrypting the message using the key
   for(i = 0; i < inputLength; i++) {
      encryptedMessage[i] = inputMessage[i] ^ encryptionKey[j];
      j++;
      if(j == keyLength) {
         j = 0;
      }
   }
   
   // Displaying the encrypted message
   printf("\nEncrypted message: ");
   for(i = 0; i < inputLength; i++) {
      printf("%c", encryptedMessage[i]);
   }
   printf("\n");
   
   return 0;
}