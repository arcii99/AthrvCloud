//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// A function to sort an array using bucket sort
void bucketSort(int arr[], int n)
{
    // Let's create BUCKET_NUM buckets
    const int BUCKET_NUM = 10;
    int i, j;
    int bucket[BUCKET_NUM];
    
    // Initialize all buckets with 0 elements initially
    for(i = 0; i < BUCKET_NUM; i++)
    {
        bucket[i] = 0;
    }
    
    // Increase the element count in the corresponding bucket 
    for(i = 0; i < n; i++)
    {
        bucket[arr[i]]++;
    }
    
    // Traverse through all the buckets and sort them individually
    for(i = 0; i < BUCKET_NUM; i++)
    {
        // Traverse through each bucket
        for(j = 0; j < bucket[i]; j++)
        {
            // Print the sorted elements
            printf("%d ", i);
        }
    }
}

// The main function
int main()
{
    printf("Welcome to the Bucket Sort Happy Code Example!\n\n");
    
    // Let's create an array with some random elements 
    int arr[] = {8, 4, 9, 1, 3, 7, 6, 2, 5, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("The original unsorted array is: \n");
    for(int i=0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    // Let's sort the array using bucket sort
    bucketSort(arr, n);
    
    printf("\n\nThe sorted array using Bucket Sort Happy Code is: \n");
    for(int i=0; i< n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n\nHooray! Bucket Sort Happy Code Example has successfully sorted the array. :)");
    return 0;
}