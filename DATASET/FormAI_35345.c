//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>

// Function to calculate the 8-bit checksum
unsigned char calculate_checksum(unsigned char *data, int length) {
    unsigned char checksum = 0;
    
    for (int i = 0; i < length; i++) {
        checksum += data[i];
    }

    return ((checksum ^ 0xFF) + 1);
}

int main() {
    unsigned char data[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    int length = sizeof(data) / sizeof(data[0]);

    printf("Data: ");

    for (int i = 0; i < length; i++) {
        printf("%02X ", data[i]);
    }

    printf("\nChecksum: %02X\n", calculate_checksum(data, length));

    return 0;
}