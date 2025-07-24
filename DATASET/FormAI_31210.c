//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
// C program to implement Bucket Sort
#include <stdio.h>
#include <stdlib.h>

// Function to sort using Bucket Sort
void Bucket_Sort(int array[], int n)
{
    // Create n empty buckets
    int bucket[n];
    for (int i = 0; i < n; i++)
        bucket[i] = 0;
 
    // Fill the buckets
    for (int i = 0; i < n; i++)
        bucket[array[i]]++;
 
    // Sort the buckets
    for (int i = 0, j = 0; i < n; i++)
        for (; bucket[i] > 0; (bucket[i])--)
            array[j++] = i;
}

// Function to print an array
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Driver code
int main()
{
    int array[] = {9, 1, 5, 7, 2, 3, 8, 6, 4, 0};
    int n = sizeof(array) / sizeof(array[0]);
    printf("Original array:\n");
    printArray(array, n);
     
    Bucket_Sort(array, n);
     
    printf("Sorted array:\n");
    printArray(array, n);
    return 0;
}