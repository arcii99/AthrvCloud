//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>

// Calculates the checksum for an array of bytes
unsigned char calculate_checksum(unsigned char* data, int length) {
    unsigned int sum = 0;
    
    // Iterate over the data
    for(int i = 0; i < length; i++) {
        sum += data[i];
    }
    
    // Return the checksum as an unsigned char
    return (unsigned char) (sum & 0xFF);
}

int main() {
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int length = sizeof(data) / sizeof(data[0]);
    
    // Calculate the checksum
    unsigned char checksum = calculate_checksum(data, length);
    
    // Output the checksum as hex
    printf("Checksum: 0x%x\n", checksum);
    
    return 0;
}