//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define POLY 0x1021 // CRC-CCITT polynomial

// Function that calculates the checksum
unsigned int calculateChecksum (unsigned char *data, unsigned int size)
{
    unsigned int crc = 0;
  
    // Loop through the data
    for (int i = 0; i < size; i++)
    {
        crc ^= (unsigned int)data[i] << 8;
        
        // Loop through each bit
        for (int j = 0; j < 8; j++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ POLY;
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}

int main()
{
    unsigned char data[] = "Hello World!"; // Test input data
    unsigned int size = sizeof(data)/sizeof(data[0]); // Calculate size of input data
    
    printf("Input Data: %s\n", data); // Print input data
    
    unsigned int checksum = calculateChecksum(data, size); // Calculate checksum
    
    printf("Checksum: %u\n", checksum); // Print checksum
    
    return 0;
}