//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate Ken Thompson style cryptographic hash
char *ken_hash(char *data) {
    int len = strlen(data);
    char *hash = malloc(sizeof(char) * (len+1));
    int i;
    for (i=0; i<len; i++) {
        hash[i] = data[i] ^ ((i+13) % 256);
    }
    hash[len] = '\0';
    return hash;
}

// Main function to test Ken Thompson style cryptographic hash
int main() {
    char *input = "Hello World!";
    char *hash = ken_hash(input);
    printf("Input: %s\n", input);
    printf("Output: ");
    int i;
    for (i=0; i<strlen(hash); i++) {
        printf("%02x", (unsigned char)hash[i]);
    }
    printf("\n");
    free(hash);
    return 0;
}