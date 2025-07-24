//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: active
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/sha.h>

int main()
{
    const char* message = "Hello World!";
    unsigned char digest[SHA256_DIGEST_LENGTH];

    SHA256((const unsigned char*) message, strlen(message), digest);

    printf("Message: %s \n", message);
    printf("Hash Value: ");
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}