//FormAI DATASET v1.0 Category: Benchmarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Surprise! We're going to give you a unique C benchmarking example program!\n");

    const int size = 10000;
    int array[size];

    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    clock_t start, end;

    // Benchmarking bubble sort
    start = clock();
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end = clock();
    printf("Sorted using bubble sort in %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    // Benchmarking quick sort
    int arr[size];
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();
    printf("Sorted using quick sort in %f seconds\n", ((double) (end - start)) / CLOCKS_PER_SEC);

    // Benchmarking linear search
    int target = rand() % 100;

    start = clock();
    int linear_index = linearSearch(array, size, target);
    end = clock();
    if(linear_index == -1) {
        printf("Target not found in array using Linear Search\n");
    } else {
        printf("Target found at index %d using Linear Search in %f seconds\n", linear_index, ((double) (end - start)) / CLOCKS_PER_SEC);
    }

    // Benchmarking binary search
    start = clock();
    int binary_index = binarySearch(arr, 0, size - 1, target);
    end = clock();
    if(binary_index == -1) {
        printf("Target not found in array using Binary Search\n");
    } else {
        printf("Target found at index %d using Binary Search in %f seconds\n", binary_index, ((double) (end - start)) / CLOCKS_PER_SEC);
    }

    return 0;
}

int linearSearch(int *array, int size, int target)
{
    for(int i = 0; i < size; i++) {
        if(array[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *array, int left, int right, int target)
{
    if(right >= left) {
        int mid = (left + right) / 2;
        if(array[mid] == target) {
            return mid;
        }
        if(array[mid] > target) {
            return binarySearch(array, left, mid - 1, target);
        }
        return binarySearch(array, mid + 1, right, target);
    }
    return -1;
}

void quickSort(int *array, int low, int high)
{
    if(low < high) {
        int partitionIndex = partition(array, low, high);
        quickSort(array, low, partitionIndex - 1);
        quickSort(array, partitionIndex + 1, high);
    }
}

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    
    return i + 1;
}