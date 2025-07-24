//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    unsigned char input[1000];
    printf("Enter Input String: ");
    fgets(input, sizeof(input), stdin);
    
    unsigned char output[SHA256_DIGEST_LENGTH];
    SHA256(input, strlen(input), output);

    printf("SHA256 Hash of Input String: ");
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}