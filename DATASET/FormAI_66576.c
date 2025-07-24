//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// function to calculate checksum
unsigned char checksum(char *data, int size)
{
    unsigned char sum = 0;
    int i;
    for(i = 0; i < size; i++)
    {
        sum += (unsigned char)data[i];
    }
    return ~sum;
}

int main()
{
    char data[1000];
    printf("Enter data: ");
    scanf("%s", data);

    int dataSize = strlen(data);
    unsigned char checkSum = checksum(data, dataSize);

    printf("Data: %s\n", data);
    printf("Checksum: 0x%02X\n", checkSum);
    printf("Ken Thompson style: "); 

    // Ken Thompson style: XOR with a constant
    int i;
    for(i = 0; i < dataSize; i++)
    {
        data[i] ^= 0x44;
    }
    printf("%s\n", data);

    return 0;
}