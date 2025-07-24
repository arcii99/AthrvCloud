//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: thoughtful
#include <stdio.h>

/* Function to calculate checksum value */
unsigned char calculateChecksum(unsigned int *data, int length)
{
    unsigned int sum = 0;
    
    for(int i=0; i<length; i++)
    {
        sum += data[i];
    }
    
    unsigned char checksum = (unsigned char)(sum & 0xFF);
    
    return checksum;
}

int main()
{
    unsigned int data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06}; // Data to calculate checksum
    
    int length = sizeof(data) / sizeof(data[0]); // Calculate length of data array
    
    unsigned char checksum = calculateChecksum(data, length); // Calculate checksum value
    
    printf("The checksum value for the given data is: 0x%02X\n", checksum);
    
    return 0;
}