//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: interoperable
#include <stdio.h>

int main()
{
    unsigned char data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // example data
    unsigned char checksum = 0; // initialize checksum

    for(int i = 0; i < 10; i++)
    {
        checksum += data[i]; // calculate checksum by adding each byte of data
    }

    checksum = ~checksum + 1; // final step of 2's complement calculation

    printf("Checksum: %02X\n", checksum); // print checksum in hexadecimal format

    return 0;
}