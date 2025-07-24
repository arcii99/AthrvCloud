//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include <stdio.h>

/*
 * A program for computing and verifying C checksums on binary files. 
 * The C checksum is a simple 8-bit checksum that is obtained by summing the 
 * bytes in a file and returning the two's complement of the sum. 
 */

#define POLYNOMIAL 0x07   // 0x07 is the standard SIP hash polynomial

unsigned char calculate_checksum(unsigned char *buffer, unsigned int length)
{
    int i;
    unsigned char checksum = 0;

    for (i = 0; i < length; i++)
    {
        checksum += buffer[i];
    }

    return ~checksum;   // return the two's complement of the sum
}

int main(int argc, char *argv[])
{
    FILE *file;
    unsigned char buffer[4096];
    unsigned int bytes_read;
    unsigned char checksum;

    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");

    if (file == NULL)
    {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        checksum = calculate_checksum(buffer, bytes_read);
    }

    fclose(file);

    printf("Checksum: %02X\n", checksum);

    return 0;
}