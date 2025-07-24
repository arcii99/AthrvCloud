//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: portable
#include <stdio.h>

// function to calculate the 8-bit checksum value of a given data
unsigned char calculate_checksum(unsigned char* data, int length) {
    unsigned char checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum += data[i];
    }
    return ~checksum; // 2's complement of the sum gives the 8-bit checksum value
}

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int length = sizeof(data)/sizeof(data[0]);
    
    // print the data and its length
    printf("Data: ");
    for (int i = 0; i < length; i++) {
        printf("%02X ", data[i]);
    }
    printf("\nLength: %d", length);
    
    // calculate the checksum value
    unsigned char checksum = calculate_checksum(data, length);
    
    // print the checksum value
    printf("\nChecksum: %02X", checksum);
    
    return 0;
}