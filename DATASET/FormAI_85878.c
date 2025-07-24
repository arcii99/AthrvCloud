//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int length = sizeof(data) / sizeof(data[0]);
    unsigned char checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum += data[i];
    }
    checksum = ~checksum + 1;
    printf("Checksum: 0x%02X\n", checksum);
    return 0;
}