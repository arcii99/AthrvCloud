//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to calculate checksum of data
int calculateChecksum(char *data)
{
    int sum = 0;
    int i;

    for(i = 0; data[i] != '\0'; i++)
    {
        sum += data[i];
        // If sum becomes greater than 255, subtract 255 from sum
        if(sum > 255)
        {
            sum = sum - 255;
        }   
    }

    // Return the complement of the sum
    return (~sum) & 0xFF;
}

int main()
{
    char data[100];
    
    printf("Enter the data: ");
    fgets(data, 100, stdin);

    // Calculate the checksum of data
    int checksum = calculateChecksum(data);

    // Print the checksum in hexadecimal format
    printf("Checksum: 0x%02X", checksum);

    return 0;
}