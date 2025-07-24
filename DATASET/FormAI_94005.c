//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
    char input[1000];
    unsigned char output[SHA256_DIGEST_LENGTH];
    int i;

    printf("Welcome to my Cryptographic hash function!\n");
    printf("Enter a string to be hashed: ");
    scanf("%s", input);

    SHA256(input, strlen(input), output);

    printf("The output hash is: ");
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++){
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}