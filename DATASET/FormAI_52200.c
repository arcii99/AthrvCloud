//FormAI DATASET v1.0 Category: Benchmarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t t1, t2;
    int n = 1000000, temp;
    int *arr = (int*)malloc(n * sizeof(int)); // dynamically allocating memory for the array

    // filling the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    // calculating the time taken for bubble sort
    t1 = clock();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    t2 = clock();

    // printing sorted array
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // calculating and printing time taken by bubble sort
    double bubble_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Time taken by bubble sort: %f seconds \n", bubble_time);

    // calculating the time taken for quick sort
    t1 = clock();
    quickSort(arr, 0, n-1);
    t2 = clock();

    // printing sorted array
    printf("Sorted array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // calculating and printing time taken by quick sort
    double quick_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Time taken by quick sort: %f seconds \n", quick_time);

    free(arr); // freeing the allocated memory
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high); // partitioning the array
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // selecting last element as pivot
    int i = (low - 1);
  
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}