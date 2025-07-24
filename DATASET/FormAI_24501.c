//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Curious Cryptographic Hash Function
unsigned long curious_hash(char *str) {

    unsigned long hash = 5381;
    int c;

    while ((c = *str++) != 0) {
        hash = ((hash << 5) + hash) ^ c; // curious operation
    }

    return hash;
}

int main() {

    char *msg = "Hello, world!";

    printf("Original message: %s\n", msg);

    unsigned long hash = curious_hash(msg);

    printf("Hash result: %lu\n", hash);

    return 0;
}