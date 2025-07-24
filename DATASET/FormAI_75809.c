//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to hold hash values
struct hash_value {
    int value1;
    int value2;
};

// Function to compute the hash values
struct hash_value get_hash(char *text) {
    int len = strlen(text);
    int value1 = 0, value2 = 1;
    for(int i=0; i<len; i++) {
        value1 = (value1 + (int)text[i]*i) % 10000;
        value2 = (value2 * ((int)text[i] % 100)) % 10000;
    }
    struct hash_value result = {value1, value2};
    return result;
}

int main() {
    char *text = "Hello, World!";
    struct hash_value hash = get_hash(text);
    printf("Hash value 1: %d\n", hash.value1);
    printf("Hash value 2: %d\n", hash.value2);
    return 0;
}