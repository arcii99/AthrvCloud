//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    char message[1024]; // set a maximum message length of 1024 characters
    printf("Enter the message you want to hash: ");
    fgets(message, 1024, stdin); // read in the message from user input

    // use the SHA-256 hashing algorithm to create a 256-bit hash value for the message
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, strlen(message));
    SHA256_Final(hash, &sha256);

    printf("The hash value of the message is: ");
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]); // print the hash value in hexadecimal format
    }
    printf("\n");

    return 0;
}