//FormAI DATASET v1.0 Category: Sorting ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to implement Cocktail sort
void cocktailSort(int arr[], int n)
{
    int swapped = 1;
    int start = 0;
    int end = n - 1;
 
    while (swapped) {
        swapped = 0;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }
        ++start;
    }
}

int main()
{
    int arr[] = { 5, 1, 4, 2, 8, 0, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cocktailSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}