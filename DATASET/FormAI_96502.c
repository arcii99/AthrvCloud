//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int arr[100000];
    srand(time(0));
    clock_t start, end;
    double time_taken;
    
    // generate random array
    for (int i = 0; i < 100000; i++) {
        arr[i] = rand() % 100;
    }
    
    // bubble sort algorithm
    start = clock();
    for (int i = 0; i < 99999; i++) {
        for (int j = 0; j < 99999-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort: %f seconds\n", time_taken);
    
    // quick sort algorithm
    start = clock();
    quickSort(arr, 0, 99999);
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort: %f seconds\n", time_taken);
    
    return 0;
}

// quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

// partition function for quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}