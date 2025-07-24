//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Checksum Calculator Program!\n");

    // Initialize variables
    unsigned char byte, sum = 0;
    int i, numBytes;
    unsigned char *bytes;

    // Read number of bytes to calculate checksum for
    printf("How many bytes would you like to calculate the checksum for? ");
    scanf("%d", &numBytes);

    // Allocate memory for the bytes
    bytes = malloc(numBytes * sizeof(unsigned char));
    if(bytes == NULL)
    {
        printf("Error allocating memory!\n");
        return 1;
    }

    // Read in the bytes
    printf("Enter the %d bytes in hexadecimal form: ", numBytes);
    for(i = 0; i < numBytes; i++)
    {
        scanf("%hhx", &byte);
        bytes[i] = byte;
    }

    // Calculate the checksum
    for(i = 0; i < numBytes; i++)
    {
        sum += bytes[i]; // Add each byte to the sum
    }

    // Output the checksum
    printf("The checksum for the %d bytes is: %02X\n", numBytes, sum);

    free(bytes); // Free memory

    printf("Thank you for using the Checksum Calculator Program!\n");

    return 0;
}