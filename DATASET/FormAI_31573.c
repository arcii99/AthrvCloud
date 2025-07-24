//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main(int argc, char *argv[]) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    char *message = "This is my message to hash.";

    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, message, strlen(message));
    MD5_Final(digest, &context);

    printf("Message: %s\n", message);
    printf("Hash: ");
    
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }

    printf("\n");

    return 0;
}