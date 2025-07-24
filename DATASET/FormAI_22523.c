//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char data[20] = {0xB5, 0x62, 0x01, 0x02, 0x00, 0x00, 0x03, 0x00, 0xFB, 0x37, 
                              0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x68, 0x03};
    // Array of data on which the checksum will be calculated (minimum 10 bytes)

    int checksum = 0;
    int i;

    for (i = 0; i < sizeof(data); i++) {
        checksum += data[i]; // Add each byte of data to the checksum
    }

    checksum = ~(checksum & 0xFF); // Invert the checksum and take the lowest byte

    printf("Checksum: 0x%02X\n", checksum);

    return 0;
}