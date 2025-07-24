//FormAI DATASET v1.0 Category: Benchmarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

double get_execution_time(struct timespec start_time, struct timespec end_time) {
    return ((end_time.tv_sec - start_time.tv_sec) * 1e9 + (end_time.tv_nsec - start_time.tv_nsec)) / 1e9;
}

void initialize_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l+i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m+1+j];
    }

    int i = 0, j = 0, k = l;
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

    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }

    int m = l + (r-l)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        int p = i + 1;
        quick_sort(arr, low, p-1);
        quick_sort(arr, p+1, high);
    }
}

int main() {
    int arr[MAX_SIZE];
    initialize_array(arr, MAX_SIZE);

    struct timespec start_time, end_time;
    double execution_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    insertion_sort(arr, MAX_SIZE);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    execution_time = get_execution_time(start_time, end_time);
    printf("Execution time of Insertion Sort: %lf s\n", execution_time);

    initialize_array(arr, MAX_SIZE);

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    merge_sort(arr, 0, MAX_SIZE - 1);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    execution_time = get_execution_time(start_time, end_time);
    printf("Execution time of Merge Sort: %lf s\n", execution_time);

    initialize_array(arr, MAX_SIZE);

    clock_gettime(CLOCK_MONOTONIC, &start_time);
    quick_sort(arr, 0, MAX_SIZE - 1);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    execution_time = get_execution_time(start_time, end_time);
    printf("Execution time of Quick Sort: %lf s\n", execution_time);

    return 0;
}