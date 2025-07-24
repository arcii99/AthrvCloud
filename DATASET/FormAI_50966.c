//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(int arr[], int n, int max_val)
{
    int i, j;
    int buckets[max_val]; // Array of buckets with maximum value of max_val
    for (i = 0; i < max_val; i++)
        buckets[i] = 0;
 
    // Increment the counter of the corresponding bucket for each element in the input array
    for (i = 0; i < n; i++)
        ++buckets[arr[i]];
 
    // Sort the elements in each bucket using insertion sort
    for (i = 0, j = 0; i < max_val; i++)
        for (; buckets[i] > 0; buckets[i]--)
            arr[j++] = i;
}
 
// Driver code
int main()
{
    int n, i;
    printf("Enter number of elements to be sorted: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int max_val = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max_val)
            max_val = arr[i];
    bucketSort(arr, n, max_val + 1);
    printf("Sorted elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}