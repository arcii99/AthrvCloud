//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t checksum(const char *data, size_t len) {
    uint8_t sum = 0;
    for (size_t i = 0; i < len; ++i) {
        sum = (sum + data[i]) % 256;
    }
    return sum;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s data\n", argv[0]);
        return 1;
    }

    const char *data = argv[1];
    size_t len = strlen(data);

    uint8_t sum = checksum(data, len);

    printf("Checksum: %02x\n", sum);
    return 0;
}