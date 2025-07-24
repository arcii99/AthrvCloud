//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

/* This function returns the checksum value for the given data array */
unsigned char calculate_checksum(unsigned char* data, int size)
{
    unsigned int sum = 0;
    
    /* First, calculate the sum of all the bytes in the data array*/
    for(int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    
    /* Then, take the one's complement of the sum and return it */
    unsigned char checksum = ~(sum & 0xFF);
    
    return checksum;
}

/* This function prints the given data array in hex format */
void print_data(unsigned char* data, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%02X ", data[i]);
    }
}

int main()
{
    /* Example data array */
    unsigned char data[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    
    /* Calculate the checksum and print it */
    unsigned char checksum = calculate_checksum(data, sizeof(data)/sizeof(data[0]));
    printf("Checksum: 0x%02X\n", checksum);
    
    /* Print the data array in hex format */
    printf("Data: ");
    print_data(data, sizeof(data)/sizeof(data[0]));
    
    return 0;
}