//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 1000

void bucket_sort(int *arr, int n)
{
    int i, j;
    int count[CAPACITY + 1] = {0};

    for (i = 0; i < n; i++)
        count[arr[i]]++;

    for (i = 0, j = 0; i <= CAPACITY; i++)
        for (; count[i] > 0; count[i]--)
            arr[j++] = i;
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Unsorted Array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucket_sort(arr, n);

    printf("\n\nSorted Array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}