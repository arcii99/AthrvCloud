//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 50

/* Function that encrypts the message using a simple substitution cypher */
void encrypt(char msg[], int key) {
   int i;
   char ch;

   for(i = 0; msg[i] != '\0'; ++i) {
      ch = msg[i];

      if(ch >= 'a' && ch <= 'z') {
         ch = ch + key;

         if(ch > 'z') {
            ch = ch - 'z' + 'a' - 1;
         }

         msg[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z') {
         ch = ch + key;

         if(ch > 'Z') {
            ch = ch - 'Z' + 'A' - 1;
         }

         msg[i] = ch;
      }
   }
}

/* Function that decrypts the message using the same key as the encryption */
void decrypt(char msg[], int key) {
   int i;
   char ch;

   for(i = 0; msg[i] != '\0'; ++i) {
      ch = msg[i];

      if(ch >= 'a' && ch <= 'z') {
         ch = ch - key;

         if(ch < 'a') {
            ch = ch + 'z' - 'a' + 1;
         }

         msg[i] = ch;
      }
      else if(ch >= 'A' && ch <= 'Z') {
         ch = ch - key;

         if(ch < 'A') {
            ch = ch + 'Z' - 'A' + 1;
         }

         msg[i] = ch;
      }
   }
}

/* Main function that demonstrates the encryption and decryption */
int main() {
   char msg[MAX_MSG_LEN];
   int key;

   // Get input from user
   printf("Enter message to be encrypted: ");
   fgets(msg, MAX_MSG_LEN, stdin);
   printf("Enter key: ");
   scanf("%d", &key);

   // Remove newline character from message input
   msg[strcspn(msg, "\n")] = '\0';

   // Encrypt message and print result
   encrypt(msg, key);
   printf("Encrypted message: %s\n", msg);

   // Decrypt message using the same key and print result
   decrypt(msg, key);
   printf("Decrypted message: %s\n", msg);

   return 0;
}