//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the checksum
unsigned char calculate_checksum(unsigned char *buffer, int size) {
    unsigned int sum = 0;
    unsigned char checksum = 0;
    int i;
    
    // Add up all the bytes in the buffer
    for (i = 0; i < size; i++) {
        sum += buffer[i];
    }
    
    // Take the lower 8 bits of the sum and invert them
    checksum = ~(sum & 0xFF);
    
    return checksum;
};

int main() {
    unsigned char message[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    unsigned char checksum = 0;
    int size = 5;
    
    // Calculate the checksum
    checksum = calculate_checksum(message, size);
    
    // Print out the checksum
    printf("Checksum = 0x%02X\n", checksum);
    
    return 0;
}