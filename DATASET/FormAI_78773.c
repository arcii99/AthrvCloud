//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

unsigned int calculate_checksum(unsigned char *data, unsigned int length) {
    unsigned int checksum = 0;

    for(int i = 0; i < length; i++) {
        checksum += data[i];
        checksum = (checksum & 0xFFFF) + (checksum >> 16);
    }

    return checksum;
}

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};
    unsigned int length = sizeof(data);
    unsigned int checksum = calculate_checksum(data, length);

    printf("Data: ");
    for(int i = 0; i < length; i++) {
        printf("%02x ", data[i]);
    }

    printf("\nChecksum: %04x", checksum);
    return 0;
}