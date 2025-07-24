//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// function to calculate checksum
unsigned char checksum(unsigned char *buffer, int size)
{
    unsigned char sum = 0;

    for (int i = 0; i < size; i++) {
        sum += buffer[i];
    }

    return (~sum) + 1;
}

int main()
{
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04};

    printf("Data: ");
    for (int i = 0; i < sizeof(data); i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    unsigned char sum = checksum(data, sizeof(data));
    printf("Checksum: %02X\n", sum);

    return 0;
}