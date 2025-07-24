//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <string.h>

unsigned char calculateChecksum(char *data, unsigned int dataSize)
{
    // Initial value for the checksum
    unsigned char checksum = 0xFF;
    
    // Iterate over each byte of the data, updating the checksum value
    for (unsigned int i = 0; i < dataSize; i++)
    {
        checksum ^= data[i];
        checksum = (checksum << 1) | (checksum >> 7);
        checksum += data[i];
    }
    
    // Return the final checksum value
    return checksum;
}

int main(void)
{
    // Example usage of the checksum calculator
    char data[] = {0x12, 0x34, 0x56, 0x78, 0x9A};
    unsigned int dataSize = sizeof(data);
    unsigned char checksum = calculateChecksum(data, dataSize);
    
    printf("Data: ");
    for (unsigned int i = 0; i < dataSize; i++)
    {
        printf("%02X ", data[i]);
    }
    printf("\nChecksum: %02X\n", checksum);
    
    return 0;
}