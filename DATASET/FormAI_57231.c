//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int len = sizeof(data);
    unsigned char checksum = 0;

    for(int i = 0; i < len; i++) {
        checksum += data[i];
    }

    // Print the calculated checksum
    printf("Checksum is: %#x\n", checksum);

    return 0;
}