//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum value of the elements in the array
#define MAX_VALUE 100 

// Helper function to swap two integers
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bucket sort function
void bucket_sort(int arr[], int size)
{
    // Create an array of MAX_VALUE buckets to store the elements
    int buckets[MAX_VALUE] = { 0 };
    
    // Count the frequency of each element and store in the buckets array
    for (int i = 0; i < size; i++) {
        buckets[arr[i]]++;
    }
    
    // Sort each bucket and combine into sorted array
    int idx = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[idx++] = i;
        }
    }
}

int main()
{
    int arr[] = { 23, 45, 12, 56, 78, 34, 89, 54, 37, 41 };
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bucket_sort(arr, size);
    
    printf("After sorting: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}