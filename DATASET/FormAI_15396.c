//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>

void bucketSort(int arr[], int n)
{
    int i, j;
    int count[n];
    
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    for (i = 0; i < n; i++)
        (count[arr[i]])++;
 
    for (i = 0, j = 0; i < n; i++)
        for (; count[i] > 0; (count[i])--)
            arr[j++] = i;
}
 
int main()
{
    int arr[] = {10, 3, 5, 8, 2, 6, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
 
    bucketSort(arr, n);
 
    printf("Sorted array is \n");
    for (i=0; i<n; i++)
        printf("%d ", arr[i]);
    return 0;
}