//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdint.h>

#define POLYNOMIAL 0xEDB88320

// Function to calculate CRC32 checksum
uint32_t crc32(const uint8_t *data, uint32_t length)
{
    // Initialize the CRC32 register to 0xFFFFFFFF
    uint32_t crc = 0xFFFFFFFF;

    for (uint32_t i = 0; i < length; i++)
    {
        uint8_t byte = data[i];

        for (uint32_t j = 0; j < 8; j++)
        {
            uint32_t mask = -(crc & 1);
            crc = (crc >> 1) ^ (mask & POLYNOMIAL);
        }

        crc ^= byte;
    }

    // Finalize the CRC32 value by XORing with 0xFFFFFFFF
    return ~crc;
}

int main()
{
    printf("Welcome to the C Checksum Calculator!\n");
    printf("Enter the data you want to calculate the checksum for:\n");

    char input[1024];
    fgets(input, 1024, stdin);

    uint32_t length = 0;
    while (input[length] != '\n')
    {
        length++;
    }

    uint32_t checksum = crc32((const uint8_t*)input, length);

    printf("The CRC32 checksum for \"%s\" is 0x%08X.\n", input, checksum);

    return 0;
}