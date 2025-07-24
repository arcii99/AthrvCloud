//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>

unsigned int checksum_calculator_recursive(unsigned char* data, unsigned int size, unsigned int checksum)
{
    if (size == 0) {
        return checksum;
    }

    checksum += *data;
    data++;

    return checksum_calculator_recursive(data, size - 1, checksum);
}

int main()
{
    unsigned char my_data[] = {0xCA, 0xFE, 0xBA, 0xBE, 0xDE, 0xAD, 0xBE, 0xEF, 0xFF};
    unsigned int my_checksum = 0xCAFEBABE;

    printf("Starting checksum: 0x%X\n", my_checksum);

    my_checksum = checksum_calculator_recursive(my_data, sizeof(my_data), my_checksum);

    printf("Final checksum: 0x%X\n", my_checksum);

    return 0;
}