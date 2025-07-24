//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ultraprecise
#include <stdio.h>

// Function to calculate the checksum of an array of integers
int calculateChecksum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum % 256;
}

int main()
{
    int myArray[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(myArray) / sizeof(myArray[0]);

    // Printing the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }

    // Calculating and printing the checksum of the array
    int checksum = calculateChecksum(myArray, size);
    printf("\nChecksum: %d\n", checksum);
    
    return 0;
}