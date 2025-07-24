//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<openssl/sha.h>

#pragma GCC diagnostic ignored "-Wunused-variable"

int main(){
    unsigned char message[] = "Hello World!";
    unsigned char digest[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, strlen(message));
    SHA256_Final(digest, &sha256);

    printf("Message:\t%s\n", message);
    printf("Digest:\t");

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", digest[i]);
    printf("\n");

    return 0;
}