//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char message[1000], encryptedMessage[1000], decryptedMessage[1000];
   int key, choice, i;

   printf("Enter the message you want to encrypt: ");
   fgets(message, sizeof(message), stdin);

   printf("Enter the encryption key: ");
   scanf("%d", &key);

   //Encrypting the message
   for(i = 0; message[i] != '\0'; ++i){
      encryptedMessage[i] = message[i] + key;
   }
   encryptedMessage[i] = '\0';

   printf("\nEncrypted message: %s", encryptedMessage);
   printf("\nPress any key to decrypt the message...");
   getchar();

   //Decrypting the message
   for(i = 0; encryptedMessage[i] != '\0'; ++i){
      decryptedMessage[i] = encryptedMessage[i] - key;
   }
   decryptedMessage[i] = '\0';

   printf("\nThe decrypted message is: %s", decryptedMessage);

   return 0;
}