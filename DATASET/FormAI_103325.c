//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void sha256(const char *input, char output[65]){
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final(hash, &sha256);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++){
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    output[64] = 0;
}

int main() {
    char input[100];
    printf("Enter input string to hash: ");
    scanf("%s", input);
    char hash[65];
    sha256(input, hash);
    printf("Hash value of string \"%s\" is: %s\n", input, hash);
    return 0;
}