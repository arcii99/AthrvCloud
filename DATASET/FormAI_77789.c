//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#define RANGE 31
// Bucket sort function
void bucketSort(int arr[], int n)
{
    int i, j, k;
    int count[RANGE];
    for (i = 0; i < RANGE; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    for (i = 0, j = 0; i < RANGE; i++)
        for (k = count[i]; k > 0; k--)
            arr[j++] = i;
}
// Print function
void printArray(int arr[], int size)
{
    int i;
    printf("Array after sorting:\n");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Main function
int main()
{
    int arr[] = { 5, 3, 2, 8, 6, 9, 11, 0, 12, 16, 24, 27, 28, 29, 30, 1, 3, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Call bucket Sort function
    bucketSort(arr, n);
    // Call print function
    printArray(arr, n);
    return 0;
}