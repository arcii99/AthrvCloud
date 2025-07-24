//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include<stdio.h>

void merge(int arr[], int start, int mid, int end);

void mergeSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

void merge(int arr[], int start, int mid, int end)
{
    int leftArrSize = mid - start + 1;
    int rightArrSize = end - mid;

    int leftArr[leftArrSize], rightArr[rightArrSize];

    int i, j;

    for(i = 0; i < leftArrSize; i++)
        leftArr[i] = arr[start + i];

    for(j = 0; j < rightArrSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;

    int k = start;

    while(i < leftArrSize && j < rightArrSize)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < leftArrSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightArrSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array is: ");
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}