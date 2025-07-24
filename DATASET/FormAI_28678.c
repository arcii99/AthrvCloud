//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    unsigned char data[] = { 0x01, 0x02, 0x03, 0x04, 0x05 };
    unsigned char checksum = 0x00;
    int i;
   
    // Calculate the checksum using XOR
    for (i = 0; i < sizeof(data); i++)
    {
        checksum ^= data[i];
    }
 
    printf("Checksum: %02X\n", checksum);
 
    return 0;
}