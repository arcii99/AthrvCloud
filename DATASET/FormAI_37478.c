//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <openssl/sha.h>

// function to generate SHA-256 hash
char* generateSHA256Hash(char *inputString, char *hashString) {
   unsigned char hash[SHA256_DIGEST_LENGTH];
   SHA256_CTX sha256;
   SHA256_Init(&sha256);
   SHA256_Update(&sha256, inputString, strlen(inputString));
   SHA256_Final(hash, &sha256);
   int i = 0;
   for(i = 0; i < SHA256_DIGEST_LENGTH; i++) {
     sprintf(hashString + (i * 2), "%02x", hash[i]);
   }
   hashString[64] = '\0';
   return hashString;
}

int main() {
   char inputString[100];
   printf("Enter string to be hashed: ");
   scanf("%s", inputString);

   char *hashString = (char*) malloc(65 * sizeof(char));
   memset(hashString, 0, 65);

   hashString = generateSHA256Hash(inputString, hashString);
   printf("SHA-256 hash of %s is: %s\n", inputString, hashString);

   free(hashString);
   return 0;
}