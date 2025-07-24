//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the checksum of the array
unsigned char calculateChecksum(unsigned char *arr, int n) 
{
    unsigned char sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    unsigned char *arr = (unsigned char *) malloc(n * sizeof(unsigned char));

    printf("Enter the elements of the array (between 0-255):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%hhu", &arr[i]); // "%hhu" specifier is used for reading unsigned char from input
    }

    unsigned char checksum = calculateChecksum(arr, n); // Calculate checksum of the array

    printf("\nChecksum of the array is: %hhu\n", checksum);

    free(arr); // Free the memory allocated for the array

    return 0;
}