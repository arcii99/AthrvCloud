//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>

/* Function to calculate the checksum */
unsigned char calc_checksum(unsigned char *data, int len) {
    unsigned char checksum = 0;
    int i;
    for (i = 0; i < len; i++) {
        checksum ^= data[i];   /* XOR operation */
    }
    return checksum;
}

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
    int len = sizeof(data) / sizeof(data[0]);
    unsigned char checksum = calc_checksum(data, len);
    printf("Checksum: %02X\n", checksum);
    return 0;
}