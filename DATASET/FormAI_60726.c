//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: innovative
#include <stdio.h>

// Calculate Checksum function
int calculateChecksum(char* data, int size)
{
    // Initialize variables
    int sum = 0;
    int i;

    // Loop through data and sum values
    for (i = 0; i < size; i++)
    {
        sum += data[i];
    }

    // Take the one's complement of the sum
    int checksum = ~(sum & 0xff);

    // Return the checksum
    return checksum;
}

int main()
{
    // Declare variables
    char data[] = "Hello, World!";
    int size = sizeof(data);
    int checksum;

    // Calculate the checksum
    checksum = calculateChecksum(data, size);

    // Print the data and checksum
    printf("Data: %s\n", data);
    printf("Checksum: %02X\n", checksum);

    // Return 0 to indicate success
    return 0;
}