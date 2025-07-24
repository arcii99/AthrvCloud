//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

// This is a function that takes in a string and returns an MD5 hash of 32 characters
char* sherlock_crypto_hash(char* input_string) {
    unsigned char md5_hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input_string, strlen(input_string), md5_hash);
    char* output_string = (char*)malloc(33 * sizeof(char));
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&output_string[i * 2], "%02x", (unsigned int)md5_hash[i]);
    }
    return output_string;
}

int main() {
    char* input_string = "The game is afoot!";
    char* output_string = sherlock_crypto_hash(input_string);
    printf("Input string: %s\n", input_string);
    printf("MD5 hash: %s\n", output_string);
    free(output_string);
    return 0;
}