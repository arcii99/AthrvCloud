//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void rotate_left(unsigned int *x, unsigned int n) {
    *x = (*x << n) | (*x >> (32 - n));
}

unsigned int my_hash(int argc, char **argv) {
    unsigned int h = 0x42;
    for (int i = 0; i < argc; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            h ^= (unsigned int) argv[i][j];
            rotate_left(&h, 9);
            int bit = (h >> 8) & 1;
            rotate_left(&h, 3);
            if (bit) {
                h ^= 0xc8;
            }
            else {
                h ^= 0x91;
            }
        }
    }
    return h;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("Usage: %s <string1> <string2> ...\n", argv[0]);
        return 1;
    }
    unsigned int h = my_hash(argc - 1, argv + 1);
    printf("Hash of ");
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("is 0x%08x\n", h);
    return 0;
}