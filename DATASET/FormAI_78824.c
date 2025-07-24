//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

//Function to calculate C Checksum
unsigned int c_checksum(const void *data, unsigned int length)
{
    const unsigned char *buf = (const unsigned char*) data;
    unsigned int sum = 0;
    int i;
 
    //Calculate the checksum
    for (i = 0; i < length; i++)
    {
        sum += buf[i];
    }
 
    //Return the complement of the checksum
    return (~sum & 0xFF);
}
 
int main()
{
    char data[] = "My Artistic C Checksum Calculator Program";
    unsigned int length = sizeof(data)-1;
    unsigned int checksum = c_checksum(data, length);

    //Print the checksum
    printf("C Checksum: 0x%X", checksum);
 
    return 0;
}