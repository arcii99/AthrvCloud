//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: beginner-friendly
#include <stdio.h>
#include <openssl/sha.h> // Include the OpenSSL library headers for sha256

int main() {
   // Declare variables
   char message[1000];
   unsigned char hash[SHA256_DIGEST_LENGTH];
   int i;

   // Accept input from user
   printf("Enter a string: ");
   scanf("%[^\n]", message);

   // Create a SHA256 cryptographic hash of the message
   SHA256(message, strlen(message), hash);

   // Print the hash as hexadecimal
   printf("\nHash value: ");
   for(i=0; i<SHA256_DIGEST_LENGTH; i++)
      printf("%02x", hash[i]);

   return 0;
}