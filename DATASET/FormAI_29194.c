//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: minimalist
#include <stdio.h>

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05}; // sample data array of bytes to be checksummed
    unsigned char checksum = 0; // initialize checksum variable
    
    for (int i = 0; i < sizeof(data); i++) {
        checksum ^= data[i]; // perform XOR operation on each byte of data
    }
    
    printf("Checksum: %02X\n", checksum); // print checksum value in hexadecimal format
    
    return 0;
}