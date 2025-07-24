//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h> // for MD5 hashing

// function to create MD5 hash of input string
void md5_hash(char *input_string, char *output_hash) {
    unsigned char md5_hash[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input_string, strlen(input_string), md5_hash);
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(output_hash + 2*i, "%02x", md5_hash[i]);
    }
}

int main() {
    char input_string[100];
    char output_hash[33]; // max size of MD5 hash is 32 bytes + null character
    printf("Enter string to be hashed: ");
    scanf("%[^\n]", input_string); // use %[\n] to receive input with spaces
    md5_hash(input_string, output_hash);
    printf("MD5 hash of %s is: %s\n", input_string, output_hash);
    return 0;
}