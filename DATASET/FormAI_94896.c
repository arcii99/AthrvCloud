//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void bubblesort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {

    int arr[100000];
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    printf("Sorting array using quicksort algorithm...\n");
    clock_t t1 = clock();
    quicksort(arr, 0, n-1);
    clock_t t2 = clock();
    double time_taken1 = ((double)(t2 - t1)/(double)CLOCKS_PER_SEC);

    printf("Sorting array using bubblesort algorithm...\n");
    clock_t t3 = clock();
    bubblesort(arr, n);
    clock_t t4 = clock();
    double time_taken2 = ((double)(t4 - t3)/(double)CLOCKS_PER_SEC);

    printf("Time taken for quicksort: %f seconds\n", time_taken1);
    printf("Time taken for bubblesort: %f seconds\n", time_taken2);

    return 0;
}