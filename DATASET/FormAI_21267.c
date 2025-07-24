//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include <stdio.h>
#include <string.h>

//Function to calculate checksum
unsigned short calculateChecksum(unsigned char message[], int length)
{
    unsigned short checksum = 0;
    int i;

    //Add each pair of bytes in message
    for (i = 0; i < length; i += 2) 
    {
        checksum += (unsigned short) ((message[i] << 8) & 0xFF00);
        if (i + 1 < length)
            checksum += (unsigned short) (message[i + 1] & 0xFF);
    }

    //Fold any overflow bits
    while (checksum >> 16)
        checksum = (checksum & 0xFFFF) + (checksum >> 16);

    //Take one's complement of final checksum
    checksum = ~checksum;

    return checksum;
}

int main()
{
    unsigned char message[] = "Hello World!";
    int length = strlen(message);
    unsigned short checksum;

    //Calculate checksum
    checksum = calculateChecksum(message, length);

    printf("Message: %s\n", message);
    printf("Checksum: 0x%X\n", checksum);

    return 0;
}