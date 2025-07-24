//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hash(char* str, int len, unsigned char* result) {

    if (len <= 0) {
        return;
    }

    result[0] = str[0];

    if (len == 1) {
        return;
    }

    unsigned char prev_hash[32];
    hash(str + 1, len - 1, prev_hash);

    for (int i = 0; i < 32; i++) {
        result[i] = prev_hash[i] ^ result[0];
    }

    return;
}

int main() {

    char str[] = "Hello, World!";
    int len = strlen(str);

    unsigned char result[32];

    hash(str, len, result);

    for (int i = 0; i < 32; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");

    exit(0);
}