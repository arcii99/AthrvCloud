//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: secure
#include <stdio.h>
#include <openssl/sha.h>

#define MAX_LEN 512

void print_hash(unsigned char *hash) {
    int i;
    for (i = 0; i < SHA512_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

void sha512(char *msg, unsigned char *hash) {
    SHA512_CTX ctx;
    SHA512_Init(&ctx);
    SHA512_Update(&ctx, msg, strlen(msg));
    SHA512_Final(hash, &ctx); 
}

int main() {
    char msg[MAX_LEN];
    unsigned char hash[SHA512_DIGEST_LENGTH];

    printf("Enter a message to hash (max %d characters): ", MAX_LEN-1);
    fgets(msg, MAX_LEN, stdin);
    msg[strcspn(msg, "\n")] = '\0'; // remove newline character
    
    sha512(msg, hash);
    printf("SHA-512 hash of message: ");
    print_hash(hash);

    return 0;
}