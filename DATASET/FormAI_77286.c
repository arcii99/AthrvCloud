//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: lively
#include <stdio.h>
#include <stdint.h>

uint32_t myHash(char* str);

int main() {
    char* msg = "Hello, world!";
    uint32_t hash = myHash(msg);
    printf("Hash value: %u\n", hash);
    return 0;
}

uint32_t myHash(char* str) {
    uint32_t result = 0;
    while (*str) {
        result ^= *str++;
        result = (result << 1) | (result >> 31); // Rotate left by 1 bit
    }
    return result;
}