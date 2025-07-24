//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>

// Function to calculate the checksum value
unsigned char checksum_calc(unsigned char *data, int size) {
    unsigned char checksum = 0;
    int i;
    for (i = 0; i < size; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
    int size = sizeof(data)/sizeof(data[0]);
    unsigned char checksum = checksum_calc(data, size);
    printf("Checksum value: 0x%02X", checksum);

    return 0;
}