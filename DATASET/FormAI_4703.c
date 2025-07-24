//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n)
{
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;
        
    for (i = 0; i < n; i++)
        ++count[(int)(arr[i])];

    for (i = 0, j = 0; i < n; ++i)
        for (; count[i] > 0; --count[i])
            arr[j++] = i + 0.0;
}

int main()
{
    int i, n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; ++i)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    printf("\nSorted array:\n");
    for (i = 0; i < n; ++i) 
        printf("%.2f ", arr[i]);
        
    return 0;
}