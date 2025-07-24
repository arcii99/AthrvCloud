//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>

/* Function to calculate the checksum for given array of bytes */
unsigned char compute_checksum(unsigned char arr[], int size) {
    unsigned char checksum = 0;
    for(int i = 0; i < size; i++) {
        checksum ^= arr[i];
    }
    return checksum;
}

int main() {
    unsigned char bytes[] = {0x45, 0x00, 0x00, 0x3c, 0x1c, 0x46, 0x40, 0x00, 0x40, 0x06, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x03, 0x0a, 0x00, 0x00, 0x02};
    int size = sizeof(bytes)/sizeof(bytes[0]);
    unsigned char checksum = compute_checksum(bytes, size);

    printf("Original Bytes: ");
    for(int i = 0; i < size; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\nCalculated Checksum: %02x\n", checksum);

    /* Changing one byte to see the effect on the checksum */
    bytes[6] = 0x41;
    checksum = compute_checksum(bytes, size);

    printf("New Bytes: ");
    for(int i = 0; i < size; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\nNew Calculated Checksum: %02x\n", checksum);

    return 0;
}