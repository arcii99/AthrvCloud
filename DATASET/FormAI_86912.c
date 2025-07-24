//FormAI DATASET v1.0 Category: Benchmarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Surprise! I am going to demonstrate a unique C Benchmarking program!\n\n");

    int arr[10000];

    // populate the array with random integers
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        arr[i] = rand() % 10000;
    }

    // benchmarking the bubble sort algorithm
    printf("Benchmarking Bubble Sort Algorithm...\n");
    clock_t start_bubble = clock();
    for (int i = 0; i < 9999; i++) {
        for (int j = 0; j < 9999 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t end_bubble = clock();
    double time_bubble = ((double) (end_bubble - start_bubble)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Algorithm took %f seconds to sort the array.\n\n", time_bubble);

    // benchmarking the quick sort algorithm
    printf("Benchmarking Quick Sort Algorithm...\n");
    clock_t start_quick = clock();
    quickSort(arr, 0, 9999);
    clock_t end_quick = clock();
    double time_quick = ((double) (end_quick - start_quick)) / CLOCKS_PER_SEC;
    printf("Quick Sort Algorithm took %f seconds to sort the array.\n\n", time_quick);

    // benchmarking the merge sort algorithm
    printf("Benchmarking Merge Sort Algorithm...\n");
    clock_t start_merge = clock();
    mergeSort(arr, 0, 9999);
    clock_t end_merge = clock();
    double time_merge = ((double) (end_merge - start_merge)) / CLOCKS_PER_SEC;
    printf("Merge Sort Algorithm took %f seconds to sort the array.\n\n", time_merge);

    printf("Surprised? These algorithms have different time complexities and are appropriate under different circumstances.\n");
    printf("I hope this unique C Benchmarking example program will inspire you to experiment with different algorithms and see for yourself which ones work best in different situations.\n");

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}