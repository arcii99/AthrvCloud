//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int calculate_checksum(int *arr, int size, int index, int prev_sum);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int checksum = calculate_checksum(arr, size, 0, 0);

    printf("Calculated checksum: %d", checksum);

    return 0;
}

int calculate_checksum(int *arr, int size, int index, int prev_sum)
{
    if(index == size) // Base case: reached end of array
    {
        return prev_sum; // Return the checksum value
    }
    else
    {
        int current_val = arr[index]; // Get value at current index
        int current_sum = prev_sum + current_val; // Calculate current sum

        // If the current sum is greater than or equal to 10, adjust it
        if(current_sum >= 10)
        {
            current_sum = current_sum % 10;
            current_sum++; // Add 1 to the sum
        }

        // Recursive call to calculate the next checksum value
        return calculate_checksum(arr, size, index+1, current_sum);
    }
}