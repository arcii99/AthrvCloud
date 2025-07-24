//FormAI DATASET v1.0 Category: Encryption ; Style: scientific
/*
 * PROGRAM NAME: C Encryption Program
 * AUTHOR: [Your Name]
 * DATE: [Current Date]
 * PURPOSE: This program demonstrates the use of encryption in C programming. 
 *          It takes user input, encrypts it using a simple substitution cipher,
 *          and outputs the encrypted message. 
 */

#include <stdio.h>
#include <string.h>

int main() {
   char message[1000];
   char ciphertext[1000];
   int key = 7;

   printf("Enter a message to encrypt: ");
   fgets(message, 1000, stdin);

   int len = strlen(message);
   // Replace each letter with a letter 'key' positions later in the alphabet
   for (int i = 0; i < len; i++) {
      if (message[i] >= 'a' && message[i] <= 'z') {
         ciphertext[i] = (char) (((message[i] - 'a') + key) % 26 + 'a');
      } else if (message[i] >= 'A' && message[i] <= 'Z') {
         ciphertext[i] = (char) (((message[i] - 'A') + key) % 26 + 'A');
      } else if (message[i] == '\n') {
         ciphertext[i] = message[i];  // keep newline
      } else {
         ciphertext[i] = message[i];  // keep non-alphabetic characters
      }
   }

   printf("Encrypted message: %s", ciphertext);
   return 0;
}