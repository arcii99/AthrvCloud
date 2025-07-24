//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: expert-level
#include <stdio.h>

int main() {

    // Declare variables
    unsigned char data[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
    unsigned char checksum = 0xFF;
    unsigned int i;

    // Iterate through the data array
    for (i = 0; i < 10; i++) {
        checksum ^= data[i]; // Calculate the XOR checksum
    }

    // Output the result
    printf("Checksum: 0x%02X\n", checksum);

    return 0;
}