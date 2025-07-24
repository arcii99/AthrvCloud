//FormAI DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int[], int, int);
int partition(int[], int, int);
void swap(int*, int*);

int main()
{
    int arr[10] = {7, 2, 8, 1, 4, 9, 5, 10, 3, 6};
    int n = sizeof(arr)/sizeof(int);

    printf("Before sorting: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    quick_sort(arr, 0, n-1);

    printf("\nAfter sorting: ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

void quick_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pivot = partition(arr, l, r);

        quick_sort(arr, l, pivot-1);
        quick_sort(arr, pivot+1, r);
    }
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for(int j=l;j<=r-1;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[r]);

    return i+1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}