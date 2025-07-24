//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void printHash(unsigned char *hash) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    // Get input string from user
    char input[100];
    printf("Enter a string to hash: ");
    scanf("%s", input);

    // Create hash
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(input, strlen(input), hash);

    // Print hash
    printf("Hash of \"%s\" is: ", input);
    printHash(hash);

    return 0;
}