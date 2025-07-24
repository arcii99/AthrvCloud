//FormAI DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>

#define ARRAY_SIZE 5 // Define the size of the input array

// Function to implement a configurable moving average filter
void moving_average_filter(int arr[], int filter_size, int output_arr[])
{
    for(int i=0; i<ARRAY_SIZE-filter_size+1; i++)
    {
        int sum = 0;
        for(int j=i; j<i+filter_size; j++)
        {
            sum += arr[j];
        }
        output_arr[i] = sum / filter_size;
    }
}

int main()
{
    int input_arr[ARRAY_SIZE] = {3, 6, 2, 1, 8};
    int filter_size = 3; // Set filter size
    int output_arr[ARRAY_SIZE-filter_size+1];

    // Print input array
    printf("Input array: ");
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        printf("%d ", input_arr[i]);
    }
    printf("\n");

    moving_average_filter(input_arr, filter_size, output_arr);

    // Print output array
    printf("Output array after moving average filter of size %d: ", filter_size);
    for(int i=0; i<ARRAY_SIZE-filter_size+1; i++)
    {
        printf("%d ", output_arr[i]);
    }
    printf("\n");

    return 0;
}