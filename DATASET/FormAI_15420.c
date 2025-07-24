//FormAI DATASET v1.0 Category: Benchmarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000000 // size of the array to be sorted

// function to swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)       
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];  
        int i = (low - 1);  
        int j;
        for (j = low; j <= high- 1; j++) {
            if (arr[j] <= pivot) {
                i++; 
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int i;
    int arr[SIZE];
    clock_t start, end;
    double bubbleSortTimeTaken, quickSortTimeTaken;
    
    // populate the array with random integers
    for (i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    
    // measure time taken for bubble sort
    start = clock();
    bubbleSort(arr, SIZE);
    end = clock();
    bubbleSortTimeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    
    // measure time taken for quick sort
    start = clock();
    quickSort(arr, 0, SIZE-1);
    end = clock();
    quickSortTimeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    
    // display time taken for both algorithms
    printf("Time taken for bubble sort: %lf seconds\n", bubbleSortTimeTaken);
    printf("Time taken for quick sort: %lf seconds\n", quickSortTimeTaken);
    
    return 0;
}