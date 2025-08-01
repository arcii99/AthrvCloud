//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

int main()
{
    int arr[100], n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("\nUnsorted Array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("\n\nSorted Array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for(j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}