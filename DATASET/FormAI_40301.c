//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define SHA256_DIGEST_LENGTH 32

int main() {

    // input message
    char message[] = "The quick brown fox jumps over the lazy dog";

    // output hash
    unsigned char output[SHA256_DIGEST_LENGTH];

    // hashing the message
    SHA256((unsigned char*)&message, strlen(message), output);

    // print the hash
    printf("Hash of input message:\n");
    for(int i=0; i<SHA256_DIGEST_LENGTH; i++){
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}