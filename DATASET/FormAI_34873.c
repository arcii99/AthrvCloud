//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>

// Function to calculate checksum
unsigned char calculate_checksum(unsigned char arr[], int size)
{
    unsigned int sum = 0;
    
    // Calculate sum of all elements
    for (int i = 0; i < size; i++)
        sum += arr[i];
    
    // Return one's complement of sum
    return (unsigned char)(~sum);
}

int main()
{
    unsigned char data[] = {0x12, 0x34, 0x56, 0x78};
    int size = sizeof(data) / sizeof(data[0]);
    
    // Calculate checksum
    unsigned char checksum = calculate_checksum(data, size);
    
    // Print original data and checksum
    printf("Original data: ");
    for (int i = 0; i < size; i++)
        printf("%02X ", data[i]);
    
    printf("\nChecksum: %02X\n", checksum);
    
    // Modify one element in the data array
    data[2] = 0x55;
    
    // Recalculate checksum
    checksum = calculate_checksum(data, size);
    
    // Print modified data and new checksum
    printf("\nModified data: ");
    for (int i = 0; i < size; i++)
        printf("%02X ", data[i]);
    
    printf("\nNew checksum: %02X\n", checksum);
    
    return 0;
}