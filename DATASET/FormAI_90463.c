//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
/* A peaceful example program to sort an array of integers using QuickSort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);

int main()
{
    int arr[10];
    int i;

    srand(time(NULL));  /* Seed random number generator */

    /* Fill array with random integers between 1 and 100 */
    for (i = 0; i < 10; i++) {
        arr[i] = (rand() % 100) + 1;
    }

    /* Print unsorted array */
    printf("Unsorted array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* Call quicksort function to sort array */
    quicksort(arr, 0, 9);

    /* Print sorted array */
    printf("Sorted array:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/* Implementation of QuickSort algorithm */
void quicksort(int *arr, int low, int high)
{
    int pivot_index;

    if (low < high) {
        pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

/* Helper function for QuickSort to partition array */
int partition(int *arr, int low, int high)
{
    int pivot_value = arr[low];
    int left_index = low;
    int right_index = high;

    while (left_index < right_index) {
        while (arr[left_index] <= pivot_value && left_index < high) {
            left_index++;
        }
        while (arr[right_index] > pivot_value) {
            right_index--;
        }
        if (left_index < right_index) {
            int temp = arr[left_index];
            arr[left_index] = arr[right_index];
            arr[right_index] = temp;
        }
    }
    arr[low] = arr[right_index];
    arr[right_index] = pivot_value;

    return right_index;
}