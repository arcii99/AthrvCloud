//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/* This function computes the checksum of a given array of integers using the C checksum algorithm. The C 
* checksum algorithm is a cyclic redundancy check algorithm that is commonly used to detect errors in 
* communication protocols. The algorithm works by performing a bitwise XOR operation on successive bytes of 
* data, and then adding the result to a running checksum value. The final checksum value is complemented and 
* returned. */

unsigned int compute_checksum(unsigned char *data, unsigned int length)
{
    unsigned int checksum = 0;
    unsigned int i = 0;
    
    for (i = 0; i < length; i++) {
        checksum += (unsigned int)data[i];
        checksum = (checksum >> 1) + (checksum << 31); // Rotate the bits of the checksum
    }
    
    return ~checksum; // Complement the checksum value
}

int main()
{
    unsigned char data[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
    unsigned int length = sizeof(data) / sizeof(data[0]);
    unsigned int checksum = compute_checksum(data, length);
    
    printf("The checksum of the given array is: %x \n", checksum);
    
    return 0;
}