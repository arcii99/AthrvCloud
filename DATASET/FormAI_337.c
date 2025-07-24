//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUM 0
#define MAX_NUM 1000
#define ARRAY_SIZE 100000

void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int arr[ARRAY_SIZE];
    int i, j;

    // Generating random array
    srand(time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = rand() % (MAX_NUM - MIN_NUM + 1) + MIN_NUM;
    }

    // Sorting the array using quicksort algorithm
    quick_sort(arr, 0, ARRAY_SIZE-1);

    // Printing out the sorted array
    printf("Sorted array: [");
    for (j = 0; j < ARRAY_SIZE; j++)
    {
        if (j == ARRAY_SIZE-1)
        {
            printf("%d]", arr[j]);
        }
        else
        {
            printf("%d, ", arr[j]);
        }
    }

    return 0;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p_index = partition(arr, low, high);

        quick_sort(arr, low, p_index-1);
        quick_sort(arr, p_index+1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low-1);
    int j, temp;

    for (j = low; j <= high-1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return (i+1);
}