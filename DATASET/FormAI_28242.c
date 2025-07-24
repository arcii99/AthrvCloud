//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/md5.h>

/* Linux-style cryptographic hash function */
void torvalds_hash(char *input, unsigned char *output) {
    MD5(input, strlen(input), output);  // We use MD5 here as an example hash function
}

int main(int argc, char **argv) {
    unsigned char hash[MD5_DIGEST_LENGTH];  // MD5_DIGEST_LENGTH is 16 bytes for MD5
    char *input;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <input string>\n", argv[0]);
        exit(1);
    }

    input = argv[1];
    torvalds_hash(input, hash);

    printf("Input string: %s\n", input);
    printf("Hash: ");
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);  // Print hash in hexadecimal format
    }
    printf("\n");

    return 0;
}