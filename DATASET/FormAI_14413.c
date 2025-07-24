//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
    char *input_string = "This is a test string.";
    unsigned char output_h[SHA512_DIGEST_LENGTH];

    SHA512(input_string, strlen(input_string), output_h);

    printf("Input string: %s\n", input_string);

    printf("Hash value: ");
    for(int i = 0; i < SHA512_DIGEST_LENGTH; i++){
        printf("%02x", output_h[i]);
    }
    printf("\n");

    return 0;
}