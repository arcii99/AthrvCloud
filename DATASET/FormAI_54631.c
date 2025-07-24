//FormAI DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <string.h>

/* function to encrypt string using Caesar Cipher */
void encrypt(char message[], int key) {
   int i;
   char ch;
   for(i = 0; message[i] != '\0'; ++i) {
      ch = message[i];
      // Encrypt uppercase characters
      if(ch >= 'A' && ch <= 'Z') {
         ch = ch + key;
         if(ch > 'Z') {
            ch = ch - 'Z' + 'A' - 1;
         }
         message[i] = ch;
      }
      // Encrypt lowercase characters
      else if(ch >= 'a' && ch <= 'z') {
         ch = ch + key;
         if(ch > 'z') {
            ch = ch - 'z' + 'a' - 1;
         }
         message[i] = ch;
      }
   }
}

int main() {
   char message[100];
   int key;

   printf("Enter a message to encrypt: ");
   fgets(message, sizeof(message), stdin);

   printf("Enter key: ");
   scanf("%d", &key);

   encrypt(message, key);
   printf("Encrypted message: %s\n", message);

   return 0;
}