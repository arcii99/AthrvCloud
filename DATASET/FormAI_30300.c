//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdint.h>

void printBinary(uint8_t);
uint8_t checksum(uint8_t[], int);

int main(void)
{
    uint8_t data[] = {0xFF, 0x00, 0x13, 0x44, 0x55};
    int dataLen = sizeof(data)/sizeof(data[0]);
    uint8_t result = checksum(data, dataLen);

    printf("Data: ");
    for(int i = 0; i < dataLen; i++)
    {
        printBinary(data[i]);
    }
    printf("\nChecksum: ");
    printBinary(result);

    return 0;
}

void printBinary(uint8_t num)
{
    for(int i = 7; i >= 0; i--)
    {
        printf("%u", (num >> i) & 1);
    }
    printf(" ");
}

uint8_t checksum(uint8_t data[], int len)
{
    uint8_t checksum = 0x00;
    for(int i = 0; i < len; i++)
    {
        checksum ^= data[i];
    }
    return checksum;
}