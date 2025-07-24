//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

/* Calculates the C checksum of the given data */
unsigned char c_checksum(unsigned char *data, int len) {
    unsigned char checksum = 0;

    /* Calculate the sum of all the bytes mod 256 */
    for (int i = 0; i < len; i++) {
        checksum += data[i];
    }

    /* Return the one's complement of the checksum */
    return ~checksum;
}

int main() {
    unsigned char buf[50] = {0x02, 0x0A, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 
                             0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x01, 0x23, 0x45,
                             0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10, 0xFF, 0xFF};

    unsigned char checksum = c_checksum(buf, sizeof(buf));

    /* Print the data and its checksum */
    printf("Data:");
    for (int i = 0; i < sizeof(buf); i++) {
        printf(" %02X", buf[i]);
    }
    printf("\nChecksum: %02X\n", checksum);

    return 0;
}