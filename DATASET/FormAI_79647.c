//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Rotate left function */
#define ROTL(x,n) (x << n) | (x >> (32 - n))

/* Hash function */
uint32_t hash_func(char *message, size_t len) {
    uint32_t h = 0x12345678; // initial hash value
    uint32_t k;
    uint32_t i;

    // Process message in 4-byte chunks
    for (i = 0; i < len / 4; i++) {
        memcpy(&k, message + 4*i, 4); // Get chunk from message
        h += k;
        h = ROTL(h, 17); // rotate left by 17 bits
        h *= 0xed558ccd; // multiplication by a prime
    }

    // Process the last few bytes of the message
    k = 0;
    for (i = len - len % 4; i < len; i++) {
        k <<= 8;
        k |= message[i];
    }
    h += k;
    h = ROTL(h, 17);
    h *= 0xed558ccd;

    return h;
}

/* Main function */
int main(void) {
    char *msg = "Hello, world!";
    uint32_t h = hash_func(msg, strlen(msg));

    printf("Hash: 0x%X\n", h);
  
    return 0;
}