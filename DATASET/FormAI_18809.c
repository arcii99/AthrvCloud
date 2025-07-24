//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>

int main()
{ 
    unsigned char data[] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };
    int idx = 0;
    unsigned char checksum = 0;

    printf("Data: ");
    for(int i = 0; i < sizeof(data); i++)
    {
        printf("%02X ", data[i]);
    }
    printf("\n");

    while(idx < sizeof(data))
    {
        checksum += data[idx];
        idx++;
    }

    printf("Checksum: %02X\n", checksum ^ 0xFF);

    return 0;
}