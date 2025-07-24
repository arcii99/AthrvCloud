//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define uchar unsigned char

uchar hex_to_int(char hex)
{
    if (hex >= '0' && hex <= '9')
    {
        return hex - '0';
    }
    else if (hex >= 'A' && hex <= 'F')
    {
        return hex - 'A' + 10;
    }
    else if (hex >= 'a' && hex <= 'f')
    {
        return hex - 'a' + 10;
    }
    else
    {
        return 0;
    }
}

uchar calculate_checksum(const uchar *data, size_t len)
{
    uchar checksum = 0;
    for (size_t i = 0; i < len; i++)
    {
        checksum += *(data + i);
    }
    return checksum;
}

int main(void)
{
    char input[256];
    uchar data[128];
    size_t len = 0;

    printf("Enter Hexadecimal Data (Max 64 Bytes): ");
    fgets(input, 256, stdin);

    for (size_t i = 0; input[i] != '\n'; i++)
    {
        if (i % 2 == 0)
        {
            uchar first_nibble = hex_to_int(input[i]);
            uchar second_nibble = hex_to_int(input[i + 1]);
            *(data + len) = (first_nibble << 4) | second_nibble;
            len++;
        }
    }

    uchar checksum = calculate_checksum(data, len);

    printf("Checksum: 0x%02X\n", checksum);

    return EXIT_SUCCESS;
}