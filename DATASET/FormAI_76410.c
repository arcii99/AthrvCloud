//FormAI DATASET v1.0 Category: Benchmarking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int main()
{
    int array[N];
    clock_t t1, t2;
    double time_taken;
    
    // initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 1000;
    }
    
    // benchmarking bubble sort
    t1 = clock();
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    t2 = clock();
    time_taken = (double)(t2 - t1) / CLOCKS_PER_SEC;
    
    printf("Bubble Sort Time Taken: %f seconds\n", time_taken);
    
    // benchmarking quick sort
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = rand() % 1000;
    }
    
    t1 = clock();
    quick_sort(array, 0, N-1);
    t2 = clock();
    time_taken = (double)(t2 - t1) / CLOCKS_PER_SEC;
    
    printf("Quick Sort Time Taken: %f seconds\n", time_taken);
    
    return 0;
}

void quick_sort(int *array, int low, int high)
{
    if (low < high) {
        int p = partition(array, low, high);
        quick_sort(array, low, p - 1);
        quick_sort(array, p + 1, high);
    }
}

int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
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