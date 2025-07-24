//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include <stdio.h>

void bucketSort(float arr[], int n)
{
    // Create n empty buckets
    int i, j;
    int bucket[n];
    for (i = 0; i < n; i++)
        bucket[i] = 0;
 
    // Add elements into the buckets
    for (i = 0; i < n; i++)
        bucket[(int)arr[i]]++;
 
    // Sort the elements in each bucket using selection sort
    for (i = 0, j = 0; i < n; i++)
        for (; bucket[i] > 0; (bucket[i])--)
            arr[j++] = i;
}
 
int main()
{
    float arr[7] = { 0.23, 0.8, 0.45, 0.09, 0.34, 0.78, 0.65 };
    int i;
 
    printf("Before sorting:\n");
    for (i = 0; i < 7; i++)
        printf("%f ", arr[i]);
 
    bucketSort(arr, 7);
 
    printf("\n\nAfter sorting:\n");
    for (i = 0; i < 7; i++)
        printf("%f ", arr[i]);
 
    return 0;
}