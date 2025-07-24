//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        printf("Please enter a string as an argument.\n");
        return 1;
    }
    
    char* input_string = argv[1];
    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input_string, strlen(input_string));
    SHA256_Final(hash, &sha256);

    printf("The input string '%s' has been hashed to: \n", input_string);

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }

    printf("\n");
    return 0;
}