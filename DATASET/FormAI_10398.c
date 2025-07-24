//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: detailed
#include <stdio.h>
#include <stdint.h>

/* function to calculate the 8-bit checksum of the given buffer */
uint8_t calculate_checksum(uint8_t *buffer, size_t size)
{
    uint8_t checksum = 0;
    
    for (size_t i = 0; i < size; i++)
    {
        checksum += buffer[i];
    }
    
    return (~checksum) + 1;
}

int main()
{
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    size_t size = sizeof(data) / sizeof(data[0]);
    
    uint8_t checksum = calculate_checksum(data, size);
    
    printf("Checksum: 0x%02X\n", checksum);
    
    return 0;
}