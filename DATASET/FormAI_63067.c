//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdint.h>

#define POLYNOMIAL 0xEDB88320

uint32_t crc_table[256];

void calculate_crc_table()
{
    uint32_t i, j;
    uint32_t crc;
    for (i = 0; i < 256; i++)
    {
        crc = i;
        for (j = 0; j < 8; j++)
        {
            if (crc & 1)
            {
                crc = (crc >> 1) ^ POLYNOMIAL;
            }
            else
            {
                crc >>= 1;
            }
        }
        crc_table[i] = crc;
    }
}

uint32_t calculate_checksum(unsigned char *data, size_t data_len)
{
    uint32_t crc = 0xFFFFFFFF;
    size_t i;
    for (i = 0; i < data_len; i++)
    {
        crc = (crc >> 8) ^ crc_table[(crc & 0xFF) ^ data[i]];
    }
    return ~crc;
}

int main()
{
    calculate_crc_table();
    unsigned char buf[1024];
    size_t len = 0;
    printf("Enter data to calculate checksum:\n");
    while (fgets(buf, sizeof(buf), stdin))
    {
        size_t n = strlen(buf);
        if (n == 1 && buf[0] == '\n')
        {
            break;
        }
        len += n;
    }
    uint32_t checksum = calculate_checksum(buf, len);
    printf("Checksum: 0x%08X\n", checksum);
    return 0;
}