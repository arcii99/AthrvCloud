//FormAI DATASET v1.0 Category: Benchmarking ; Style: standalone
#include<stdio.h>
#include<time.h>
#define SIZE 1000000

// Function to generate random numbers
void generateRandomNumbers(int arr[]) {
    srand(time(NULL));
    for(int i=0; i<SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

// Function to perform quicksort
void quicksort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }
    int pivot = arr[start];
    int i = start;
    int j = end;
    while(i <= j) {
        while(arr[i] < pivot) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }
        if(i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if(start < j) {
        quicksort(arr, start, j);
    }
    if(end > i) {
        quicksort(arr, i, end);
    }
}

int main() {
    int arr[SIZE];
    generateRandomNumbers(arr);
    clock_t t;
    t = clock();
    quicksort(arr, 0, SIZE-1);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    printf("QuickSort took %f seconds to execute \n", time_taken);
    return 0;
}