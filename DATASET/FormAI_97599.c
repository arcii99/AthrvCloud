//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

// Quick Sort Algorithm
void quicksort(int *arr, int low, int high) {
    int i = low, j = high;
    int pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j) {
        quicksort(arr, low, j);
    }
    if (i < high) {
        quicksort(arr, i, high);
    }
}

// Merge Sort Algorithm
void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[MAX_SIZE];
    int i;

    // Seed the random number generator
    srand(time(NULL));

    // Fill the array with random integers
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    // Benchmark Quick Sort Algorithm
    clock_t t;
    t = clock();
    quicksort(arr, 0, MAX_SIZE - 1);
    t = clock() - t;
    double time_taken_qs = ((double)t) / CLOCKS_PER_SEC;

    // Fill the array with random integers again
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % MAX_SIZE;
    }

    // Benchmark Merge Sort Algorithm
    t = clock();
    mergesort(arr, 0, MAX_SIZE - 1);
    t = clock() - t;
    double time_taken_ms = ((double)t) / CLOCKS_PER_SEC;

    // Print the results
    printf("Quick Sort Algorithm Time Taken: %lf seconds\n", time_taken_qs);
    printf("Merge Sort Algorithm Time Taken: %lf seconds\n", time_taken_ms);

    return 0;
}