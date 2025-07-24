//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000 // Define the number of elements in the array

// Define the function to generate an array of random integers
void generate_array(int *arr, int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000 + 1; // Generate integers between 1 and 1000
    }
}

// Define the function to print the array
void print_array(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Define the function to perform selection sort on the array
void selection_sort(int *arr, int n)
{
    int i, j, min_idx, temp;
    for(i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main()
{
    int *arr = (int *)malloc(N * sizeof(int)); // Allocate memory for the array
    if(arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    generate_array(arr, N);
    printf("Unsorted array:\n");
    print_array(arr, N);
    
    selection_sort(arr, N);
    printf("Sorted array:\n");
    print_array(arr, N);
    
    free(arr); // Free the allocated memory
    
    return 0;
}