//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>

int main()
{
    unsigned char input_data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
    unsigned char checksum = 0;
    int i;

    printf("Input data: ");
    for (i = 0; i < sizeof(input_data); i++)
    {
        printf("%02x ", input_data[i]);
        checksum += input_data[i];
    }

    printf("\nChecksum: %02x\n", checksum);

    return 0;
}