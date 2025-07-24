//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n)
{
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        (count[(int)arr[i]])++;
    for (i = 0, j = 0; i < n; i++)
        for (; count[i] > 0; (count[i])--)
            arr[j++] = i;
}

int main()
{
    int n = 7;
    float arr[] = {0.23, 0.88, 0.42, 0.06, 0.45, 0.81, 0.16};
    int i;
 
    printf("Unsorted array is: \n");
    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");

    bucketSort(arr, n);
 
    printf("Sorted array is: \n");
    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
 
    return 0;
}