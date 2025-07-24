//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include <stdio.h>

unsigned char checksum(unsigned char *data, int length) {
    unsigned char sum = 0;
    for (int i = 0; i < length; i++) {
        sum += data[i];
    }
    return sum;
}

int main() {
    unsigned char data[] = {0x10, 0x20, 0x30, 0x40};
    int length = sizeof(data) / sizeof(unsigned char);
    printf("Data: ");
    for (int i = 0; i < length; i++) {
        printf("%02X ", data[i]);
    }
    printf("\nChecksum: %02X\n", checksum(data, length));
    return 0;
}