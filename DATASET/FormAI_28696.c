//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: synchronous
#include <stdio.h>
#include <stdint.h>

#define POLYNOMIAL 0x1021

uint16_t crc16(uint8_t *data, uint32_t length)
{
    uint16_t crc = 0xFFFF;
    for (uint32_t i = 0; i < length; i++)
    {
        crc ^= (uint16_t)data[i] << 8;
        for (uint8_t j = 0; j < 8; j++)
        {
            if (crc & 0x8000)
            {
                crc = (crc << 1) ^ POLYNOMIAL;
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
    uint8_t data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint32_t length = sizeof(data)/sizeof(data[0]);
    uint16_t checksum = crc16(data, length);
    printf("Checksum: 0x%04X\n", checksum);
    return 0;
}