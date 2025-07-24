//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
   char message[MAX_SIZE], cipher[MAX_SIZE];
   int i, key;

   // Read the message to be encrypted
   printf("Enter the message to be encrypted: ");
   fgets(message, MAX_SIZE, stdin);

   // Read the encryption key
   printf("Enter the encryption key (0-25): ");
   scanf("%d", &key);

   // Apply Caesar cipher algorithm
   for(i = 0; message[i] != '\0'; ++i) {
      if(message[i] >= 'a' && message[i] <= 'z') {
         cipher[i] = 'a' + (message[i] - 'a' + key) % 26;
      } else if(message[i] >= 'A' && message[i] <= 'Z') {
         cipher[i] = 'A' + (message[i] - 'A' + key) % 26;
      } else {
         cipher[i] = message[i];
      }
   }
   cipher[i] = '\0';

   // Print the encrypted message
   printf("\nEncrypted message: %s\n", cipher);

   // Apply Caesar cipher decryption
   for(i = 0; cipher[i] != '\0'; ++i) {
      if(cipher[i] >= 'a' && cipher[i] <= 'z') {
         message[i] = 'a' + (cipher[i] - 'a' - key + 26) % 26;
      } else if(cipher[i] >= 'A' && cipher[i] <= 'Z') {
         message[i] = 'A' + (cipher[i] - 'A' - key + 26) % 26;
      } else {
         message[i] = cipher[i];
      }
   }
   message[i] = '\0';

   // Print the decrypted message
   printf("\nDecrypted message: %s\n", message);

   return 0;
}