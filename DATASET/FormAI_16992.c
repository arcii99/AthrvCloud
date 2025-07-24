//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>

int main()
{
    int data[10], checksum = 0;

    // Input data
    printf("Enter 10 numbers to calculate checksum:\n");
    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &data[i]);
        // Add to checksum
        checksum += data[i];
    }

    // Print checksum
    printf("\nThe checksum is: %d\n", checksum);

    // Split checksum into bytes
    int checksumByte1 = (checksum >> 8) & 0xFF;
    int checksumByte2 = checksum & 0xFF;

    // Print bytes
    printf("\nChecksum Byte 1: %d\n", checksumByte1);
    printf("Checksum Byte 2: %d\n", checksumByte2);

    // Add bytes to get final checksum
    int finalChecksum = checksumByte1 + checksumByte2;

    // Print final checksum
    printf("\nThe final checksum is: %d\n", finalChecksum);

    return 0;
}