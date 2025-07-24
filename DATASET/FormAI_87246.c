//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: configurable
#include <stdio.h>

int main() {
    unsigned char data[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    int length = sizeof(data);
    unsigned char checksum = 0; // Initialize checksum variable

    // Calculate checksum
    for(int i=0; i<length; i++) {
        checksum += data[i];
    }

    // Print checksum
    printf("Checksum: 0x%02X\n", checksum);

    return 0;
}