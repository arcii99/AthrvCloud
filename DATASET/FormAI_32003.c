//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include<stdio.h>

int main() {
    unsigned char data[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x05};
    int i, sum = 0;
    for (i = 0; i < sizeof(data); i++) {
        sum += data[i];
    }
    unsigned char checksum = (unsigned char)(0xFF - (sum & 0xFF));

    printf("Checksum: 0x%02X\n", checksum);
    return 0;
}