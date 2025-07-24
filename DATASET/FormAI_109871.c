//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1000000

// function to swap two values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort algorithm
void bubble_sort(int arr[], int n)
{
    int i, j;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

// quick sort algorithm
void quick_sort(int arr[], int low, int high)
{
    if(low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
    }
}

// function to find partition point for quicksort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

// driver function to execute sorting algorithms
int main()
{
    int arr[MAX_SIZE];
    int n, i;

    // initialize array with random values
    for(i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand();
    }

    // execute bubble sort and measure time taken
    clock_t start_bubble = clock();
    bubble_sort(arr, MAX_SIZE);
    clock_t end_bubble = clock();
    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;

    // execute quick sort and measure time taken
    clock_t start_quick = clock();
    quick_sort(arr, 0, MAX_SIZE-1);
    clock_t end_quick = clock();
    double time_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;

    // print results
    printf("Time taken for bubble sort: %lf seconds\n", time_bubble);
    printf("Time taken for quick sort: %lf seconds\n", time_quick);

    return 0;
}