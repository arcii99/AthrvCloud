//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* ephemeral_hash(char* input);

int main() {
    char input[1024];
    printf("Enter a string to hash: ");
    scanf("%[^\n]", input);

    char* hash = ephemeral_hash(input);
    printf("Hash: %s", hash);

    free(hash);
    return 0;
}

char* ephemeral_hash(char* input) {
    int len = strlen(input);
    char* hash = (char*)malloc(len * sizeof(char));
    int i, j;
    char temp;

    for (i = 0; i < len; i++) {
        // Calculate hash value
        hash[i] = input[i] ^ (i * 31);

        // Perform confusion permutation
        for (j = i+1; j < len; j++) {
            if (hash[j] < hash[i]) {
                temp = hash[j];
                hash[j] = hash[i];
                hash[i] = temp;
            }
        }

        // Perform diffusion permutation
        for (j = 0; j < len; j++) {
            hash[j] = (hash[j] + hash[i]) % 256;
        }
    }

    return hash;
}