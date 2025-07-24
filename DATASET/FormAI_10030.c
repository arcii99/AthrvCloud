//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Calculator function that calculates the checksum for a given input data array
 */
unsigned char checksum(unsigned char *data, int len) {
    unsigned int sum = 0;
    bool flip = true;
    for (int i = 0; i < len; i++) {
        sum += flip ? data[i] : ~data[i];
        flip = !flip;
    }
    return ~sum;
}

int main() {
    unsigned char data[6] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
    unsigned char result = checksum(data, 6);
    printf("Checksum = 0x%02X\n", result);
    return 0;
}