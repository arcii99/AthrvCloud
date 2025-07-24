//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdint.h>

// Function to calculate checksum
uint16_t calc_checksum(uint8_t input[], uint32_t len)
{
    uint32_t sum = 0;
    uint16_t checksum = 0;

    for(uint32_t i = 0; i < len; i++)
    {
        // Add each byte to the sum
        sum += input[i];

        // Wrap the sum if it exceeds 16-bits
        if(sum >> 16)
        {
            sum = (sum & 0xFFFF) + (sum >> 16);
        }
    }

    // Get the 1's complement of the sum
    checksum = ~sum;

    return checksum;
}

int main()
{
    // Example input buffer
    uint8_t input[] = {0x45, 0x00, 0x00, 0x3C, 0x1F, 0x46, 0x40, 0x00,
                       0x40, 0x06, 0xC3, 0xB6, 0x0A, 0x0A, 0x64, 0x02,
                       0x0A, 0x0A, 0x64, 0x01};
    
    uint32_t len = sizeof(input) / sizeof(input[0]);

    // Calculate the checksum and print the result
    uint16_t checksum = calc_checksum(input, len);
    printf("Checksum: 0x%X\n", checksum);

    return 0;
}