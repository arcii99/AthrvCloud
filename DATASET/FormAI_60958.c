//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    unsigned char data[] = {0xF1, 0x2C, 0x45, 0x63, 0x5A, 0x71};
    unsigned char checksum = 0;

    for (int i = 0; i < sizeof(data); i++) {
        checksum ^= data[i];
    }

    printf("The checksum of the data is: %02X\n", checksum);

    return 0;
}