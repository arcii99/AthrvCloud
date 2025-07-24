//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: portable
#include <stdio.h>
#include <stdint.h>

uint16_t calculateChecksum(const uint8_t *data, size_t length)
{
    uint16_t checksum = 0;
    
    // Iterate through the data byte by byte
    for (size_t i = 0; i < length; i++)
    {
        checksum += data[i];
        if (checksum > UINT8_MAX)
        {
            checksum -= UINT8_MAX + 1;
        }
    }
    
    // Invert the checksum to get the final result
    checksum = ~checksum;
    
    return checksum;
}

int main()
{
    // Test data
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    size_t length = sizeof(data) / sizeof(data[0]);
    
    // Calculate the checksum
    uint16_t checksum = calculateChecksum(data, length);
    
    // Print the result in hex format
    printf("Checksum: 0x%04X\n", checksum);
    
    return 0;
}