//FormAI DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

typedef unsigned char byte;

int main()
{
    byte checksum[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    byte data[21];
    byte result[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    printf("Enter the data (20 bytes):\n");
    for(int i=0; i<20; i++)
    {
        scanf("%d", &data[i]);
    }

    for(int i=0; i<20; i++)
    {
        for(int j=0; j<8; j++)
        {
            result[j] ^= (data[i] & (1 << j)) >> j;
        }
    }

    for(int i=0; i<8; i++)
    {
        result[i] ^= checksum[i];
    }

    printf("Checksum Result: ");
    for(int i=0; i<8; i++)
    {
        printf("%02x ", result[i]);
    }

    printf("\n");
    return 0;
}