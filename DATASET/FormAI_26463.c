//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to generate the SHA256 hash of a string and return it as a hex string
char* sha256(char *str){
     // Salt value hardcoded for this example
     const char *salt = "SALT";
     int len = strlen(str) + strlen(salt);
     char *concat = malloc(len + 1);
     strcpy(concat, str);
     strcat(concat, salt);

     unsigned char hash[SHA256_DIGEST_LENGTH];
     SHA256(concat, len, hash);

     char *hexHash = malloc(SHA256_DIGEST_LENGTH*2 + 1);
     for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
         sprintf(&hexHash[i*2], "%02x", hash[i]);
     }

     free(concat);
     return hexHash;
}

int main(){
     // Example usage of the sha256 hash function
     char *hash = sha256("my password");
     printf("Hash: %s\n", hash);
     free(hash);
     return 0;
}