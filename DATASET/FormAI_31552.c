//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate checksum
unsigned char calculateChecksum(unsigned char arr[], int size)
{
    unsigned int sum = 0;
    unsigned char checksum = 0;

    // Add all the elements of the array
    for (int i=0; i<size; i++)
    {
        sum += arr[i];
    }

    // Take the one's complement of the sum
    checksum = ~sum;

    return checksum;
}

int main()
{
    unsigned char arr[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    // Print the original array
    printf("Original array of size %d:\n", arr_size);
    for (int i=0; i<arr_size; i++)
        printf("%02x ", arr[i]);

    // Calculate the checksum
    unsigned char checksum = calculateChecksum(arr, arr_size);

    // Print the checksum
    printf("\n\nChecksum: %02x\n", checksum);

    return 0;
}