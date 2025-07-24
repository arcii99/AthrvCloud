//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include <stdio.h>

// function to calculate checksum of an array of integers
int checksum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum % 256;
}

int main()
{
    // sample array of integers
    int arr[] = {10, 2, 30, 4, 50, 6, 70, 8, 90, 10, 110};
    
    // calculate checksum of the array
    int chksum = checksum(arr, sizeof(arr)/sizeof(int));
    
    // print the result
    printf("Checksum of the array is: %d\n", chksum);
    
    return 0;
}