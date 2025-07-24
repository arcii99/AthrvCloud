//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: energetic
#include <stdio.h>
#include <openssl/sha.h>

int main() {
    unsigned char input[1000];
    int i;
    printf("Enter a string to hash: ");
    scanf("%s", input);

    unsigned char hash[SHA256_DIGEST_LENGTH];

    SHA256(input, strlen(input), hash);

    printf("\nYour SHA256 hash is: ");
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++){
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}