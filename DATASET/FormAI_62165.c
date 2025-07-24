//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>

// calculate checksum of a given data using XOR
unsigned char checksum(const unsigned char *data, int len) {
    unsigned char c = 0;
    for (int i = 0; i < len; i++) {
        c ^= data[i];
    }
    return c;
}

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int len = sizeof(data)/sizeof(data[0]);
    unsigned char sum = checksum(data, len);

    printf("Checksum of data: %02x\n", sum);

    return 0;
}