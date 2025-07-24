//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* brave_hash (char *input) {
    int len = strlen(input);
    unsigned char hash[32];
    char* output = (char*) malloc(65 * sizeof(char));
    int i = 0;
    hash[0] = (unsigned char) input[0];
    for (i=1; i < len; i++) {
        hash[i%32] = (unsigned char) (hash[i%32] ^ input[i]);
        hash[(i%32 + 1) % 32] = (unsigned char) (hash[(i%32 + 1) % 32] ^ (input[i] + i%32));
    }
    for (i=0; i<32; i++) {
        char temp[3];
        sprintf(temp, "%02x", hash[i]);
        strcat(output, temp);
    }
    return output;
}

int main() {
    char* input = (char*) malloc(50 * sizeof(char));
    printf("Enter input to hash: ");
    scanf("%s", input);
    char* hash = brave_hash(input);
    printf("Hash output: %s\n", hash);
    free(input);
    free(hash);
    return 0;
}