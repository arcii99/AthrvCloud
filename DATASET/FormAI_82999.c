//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: minimalist
#include <stdio.h>

#define POLY 0x8408 // CRC-16-CCITT Polynomial
#define WIDTH 16 // Checksum width

/* Calculate checksum of given data buffer */
unsigned short calc_crc16(unsigned char* data, int len)
{
    unsigned short current_crc = 0;
    int i, j;

    for (i = 0; i < len; i++)
    {
        current_crc ^= ((unsigned short)data[i] << (WIDTH - 8));
        for (j = 0; j < 8; j++)
        {
            if ((current_crc & 0x8000) != 0)
            {
                current_crc = (current_crc << 1) ^ POLY;
            }
            else
            {
                current_crc <<= 1;
            }
        }
    }

    return current_crc;
}

int main()
{
    unsigned char data[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    int len = sizeof(data) / sizeof(data[0]);
    unsigned short checksum = calc_crc16(data, len);

    printf("Checksum: 0x%X\n", checksum);

    return 0;
}