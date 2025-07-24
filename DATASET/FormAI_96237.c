//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate array of random integers
void randomArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // generate random integers between 0 and 999
    }
}

// function to print array
void printArray(int arr[], int n) {
    printf("[ ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort algorithm
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// quicksort algorithm
void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;
        while(i <= j) {
            while((i <= high) && (arr[i] <= pivot)) {
                i++;
            }
            while((j >= low) && (arr[j] > pivot)) {
                j--;
            }
            if(i <= j) {
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[low], &arr[j]);
        quicksort(arr, low, j-1);
        quicksort(arr, j+1, high);
    }
}

// main function, which benchmarks the performance of bubble sort and quicksort on arrays of different sizes
int main() {
    srand(time(NULL)); // seed random number generator with current time
    int n = 10; // initial array size
    int arr[n];
    double bubbleTime, quicksortTime;

    printf("Array size\tBubble sort\tQuicksort\n");
    for(int i = 0; i < 5; i++) {
        randomArray(arr, n);

        // benchmark bubble sort
        clock_t start = clock();
        bubbleSort(arr, n);
        clock_t end = clock();
        bubbleTime = (double)(end - start) / CLOCKS_PER_SEC;

        randomArray(arr, n);

        // benchmark quicksort
        start = clock();
        quicksort(arr, 0, n-1);
        end = clock();
        quicksortTime = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t\t%.6f\t%.6f\n", n, bubbleTime, quicksortTime);

        n *= 10; // increase array size by factor of 10
    }

    return 0;
}