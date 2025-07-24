//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include <stdio.h>

unsigned int calculate_checksum(unsigned char* data, int data_length)
{
    unsigned int checksum = 0;
    
    for(int i = 0; i < data_length; i++)
    {
        checksum += data[i];
    }
    
    return checksum;
}

int main()
{
    unsigned char data[] = "Hello World!";
    int data_length = 12;
    
    unsigned int checksum = calculate_checksum(data, data_length);
    
    printf("The checksum of the data is: %u\n", checksum);
    
    return 0;
}