//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short crc16_ccitt(const unsigned char* buf, int len)
{
    unsigned short crc = 0xFFFF;
    int i;

    for (i = 0; i < len; ++i)
    {
        crc ^= buf[i] << 8;

        for (int j = 0; j < 8; ++j)
        {
            if (crc & 0x8000)
                crc = (crc << 1) ^ 0x1021;
            else
                crc <<= 1;
        }
    }

    return crc;
}

int main()
{
    char message[100], checksum[5];
    int i, len;
    unsigned short crc;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    len = strlen(message);

    if (message[len - 1] == '\n')
        message[len - 1] = '\0';

    // Calculate Checksum
    crc = crc16_ccitt(message, len);
    sprintf(checksum, "%04X", crc);

    printf("\nMessage : %s", message);
    printf("\nChecksum: %s\n", checksum);

    return 0;
}