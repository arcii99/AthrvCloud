//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include <stdio.h>

#define POLYNOMIAL 0xEDB88320L

unsigned long crc_table[256];

void init_crc_table()
{
    unsigned long c;
    int n, k;

    for (n = 0; n < 256; n++)
    {
        c = (unsigned long)n;
        for (k = 0; k < 8; k++)
        {
            if (c & 1)
            {
                c = POLYNOMIAL ^ (c >> 1);
            }
            else
            {
                c = c >> 1;
            }
        }
        crc_table[n] = c;
    }
}

unsigned long calculate_crc(unsigned char *data, int length)
{
    unsigned long crc = 0xffffffff;
    int i;

    for (i = 0; i < length; i++)
    {
        crc = crc_table[(crc ^ data[i]) & 0xff] ^ (crc >> 8);
    }

    return crc ^ 0xffffffff;
}

int main()
{
    init_crc_table();

    unsigned char data[] = "Hello, World!";
    int length = sizeof(data) - 1;

    unsigned long crc = calculate_crc(data, length);

    printf("CRC32 of \"%s\" is %lu\n", data, crc);

    return 0;
}