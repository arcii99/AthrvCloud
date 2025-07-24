//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surprised
#include <stdio.h>

// Function to calculate the checksum of a given data array
int calculateChecksum(int data[], int length)
{
    int sum = 0;

    for(int i=0; i<length; i++)
    {
        sum += data[i];
    }

    return sum % 256;
}

int main()
{
    int data[] = { 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 }; // Fibonacci sequence for testing
    
    int checksum = calculateChecksum(data, sizeof(data)/sizeof(int));
    
    printf("The checksum of the given data is: %d\n", checksum);
    printf("WOW! This is amazing!\n");
    
    return 0;
}