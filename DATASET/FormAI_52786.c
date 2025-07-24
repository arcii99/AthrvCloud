//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char message[100], key[100];
   int i, j, choice, message_len, key_len;
   printf("Enter a message to encrypt: ");
   fgets(message, sizeof(message), stdin);
   printf("Enter a key: ");
   fgets(key, sizeof(key), stdin);
   message_len = strlen(message)-1;
   key_len = strlen(key)-1;

   printf("Select an encryption method: \n");
   printf("1. Vigenere Cipher\n");
   printf("2. Caesar Cipher\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         printf("Vigenere Cipher\n");
         for(i = 0, j = 0; i < message_len; i++, j++) {
            if(j == key_len) {
               j = 0;
            }
            message[i] = (((message[i] - 'A') + (key[j] - 'A')) % 26) + 'A';
         }
         printf("Encrypted message: %s\n", message);
         break;

      case 2:
         printf("Caesar Cipher\n");
         for(i = 0; i < message_len; i++) {
            message[i] = ((message[i] - 'A' + key[0] - '0') % 26) + 'A';
         }
         printf("Encrypted message: %s\n", message);
         break;

      default:
         printf("Invalid choice\n");
   }

   return 0;
}