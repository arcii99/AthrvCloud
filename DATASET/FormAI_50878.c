//FormAI DATASET v1.0 Category: Benchmarking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

// Function to generate random numbers
void generateRandomArray(int arr[]) {
    srand(time(0));
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100;
    }
}

// Function to perform bubble sort
void bubbleSort(int arr[]) {
    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        for(int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int i = low, j = high, pivot = arr[low];
        while(i < j) {
            while(arr[i] <= pivot && i < high)
                i++;
            while(arr[j] > pivot)
                j--;
            if(i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        arr[low] = arr[j];
        arr[j] = pivot;
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}

int main() {
    int arr[ARRAY_SIZE];

    generateRandomArray(arr);

    clock_t start = clock();
    bubbleSort(arr);
    clock_t end = clock();
    double time_taken_bubble = ((double)(end - start))/CLOCKS_PER_SEC;

    generateRandomArray(arr);

    start = clock();
    quickSort(arr, 0, ARRAY_SIZE-1);
    end = clock();
    double time_taken_quick = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Time taken for Bubble Sort: %f \n", time_taken_bubble);
    printf("Time taken for Quick Sort: %f \n", time_taken_quick);

    return 0;
}